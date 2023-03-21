import hashlib
import json
import rsa
import fire
import os
from rich import print
from rsa import PublicKey, common, transform, core
from Crypto import Random
from Crypto.PublicKey import RSA
from Crypto.Cipher import PKCS1_v1_5
import base64



class Utils:
    def __init__(self):
        pass

    @staticmethod
    # 公钥解密
    def public_key_decrypt(rsa_public_key_der_b64, qr_code_cipher_b64):
        qr_code_cipher = base64.b64decode(qr_code_cipher_b64)
        public_key = base64.b64decode(rsa_public_key_der_b64)
    
        try:
            rsa_public_key = PublicKey.load_pkcs1_openssl_der(public_key)
            cipher_text_bytes = transform.bytes2int(qr_code_cipher)
            decrypted_text = core.decrypt_int(cipher_text_bytes, rsa_public_key.e, rsa_public_key.n)
            final_text = transform.int2bytes(decrypted_text)
            final_qr_code = final_text[final_text.index(0) + 1:]
            return final_qr_code.decode()
        except Exception as ex:
            # _logger.exception(ex)
            return None

    @staticmethod
    def hash(content):
        md5 = hashlib.md5()
        md5.update(content.encode('utf-8'))
        res = md5.hexdigest().encode('utf-8')
        return res

    @staticmethod
    def create_keys(path='./keys/'):
        try:
            os.mkdir(path)
        except FileExistsError:
            pass
        finally:
            publicKey, privateKey = rsa.newkeys(512)
            public_file = os.path.join(path, 'publicKey.key')
            private_file = os.path.join(path, 'privateKey.key')
            with open(public_file, 'wb+') as f:
                pk = rsa.PublicKey.save_pkcs1(publicKey, format='PEM')
                f.write(pk)
                print("[bold magenta]保存公钥成功[/bold magenta]!")
            with open(private_file, 'wb+') as f:
                pk = rsa.PrivateKey.save_pkcs1(privateKey, format='PEM')
                f.write(pk)
                print("[bold magenta]保存私钥成功[/bold magenta]!")
        return publicKey, privateKey

    @staticmethod
    def read_public_key(file_path):
        with open(file_path, 'rb') as f:
            public_file = f.read()
            pubkey = rsa.PublicKey.load_pkcs1(keyfile=public_file)
            print("[bold magenta]读取公钥成功[/bold magenta]!")
        return pubkey

    @staticmethod
    def read_private_key(file_path):
        with open(file_path, 'rb') as f:
            private_file = f.read()
            privkey = rsa.PrivateKey.load_pkcs1(keyfile=private_file)
            print("[bold magenta]读取私钥成功[/bold magenta]!")
        return privkey

    @staticmethod
    # 公钥加密 or 私钥加密
    def rsa_encrypt(obj, pub_key):
        encrypted_msg = obj.encode()
        # 加密长度有最大限制，需要分块加密。否则会报类似如下的错误：OverflowError: 295 bytes needed for message, but there is only space for 53。
        res = []
        length = len(obj)
        default_length = 53
        for i in range(0, length, default_length):
            res.append(rsa.encrypt(encrypted_msg[i:i+default_length], pub_key))
        byte_data = b''.join(res)
        return byte_data

    @staticmethod
    # 私钥解密
    def rsa_decrypt(obj, priv_key):
        length = len(obj)
        default_length = 53
        res = []
        for i in range(0, length, default_length):
            res.append(rsa.decrypt(obj[i:i+default_length], priv_key))
        return b''.join(res)

    @staticmethod
    def dictify(keys, values):
        dict = {}
        for index, key in enumerate(keys):
            dict[key] = values[index]
        return dict

    @staticmethod
    def dict2json(dict):
        print(type(dict))
        j = json.dumps(dict)
        return j

class Auth:
    def __init__(self, auth_institution, white_list, applicant_pub_key, another_info=None):
        self.auth_institution = auth_institution
        self.white_list = white_list
        self.another_info = another_info
        self.pub_key, self.priv_key = Utils.create_keys()
        self.applicant_pub_key = str(applicant_pub_key)

    def send_certificate(self):
        keys = ['auth_institution', 'another_info', 'pub_key']
        values = [self.auth_institution, self.another_info,
                  self.applicant_pub_key]
        dict = Utils.dictify(keys, values)
        j = Utils.dict2json(dict)
        hashed_content = Utils.hash(j)
        # print(type(hashed_content), hashed_content)
        keys = ['hash', 'info']
        values = [str(hashed_content), dict]
        ca = Utils.dict2json(Utils.dictify(keys, values))
        encrypted_content = Utils.rsa_encrypt(ca, self.priv_key)
        return encrypted_content

    def verificate_certificate(self, ca, pub_key):
        ca = Utils.rsa_decrypt(ca, pub_key)

        

if __name__ == '__main__':
    applicant_pub_key = Utils.read_public_key('/root/catkin_ws/src/cyber_security_lab_1/scripts/key/publicKey.key')
    auth = Auth('cquty', ['cquty', 'cqu'], applicant_pub_key)
    en_res = auth.send_certificate()
    en_res = base64.b64encode(en_res)
    print(en_res)
    pub_key = Utils.read_public_key('/root/catkin_ws/src/lab2/scripts/keys/publicKey.key')
    # de_res = Utils.rsa_decrypt(en_res, pub_key)
    print('[blue]--------------[/blue]')
    de_res = Utils.public_key_decrypt(pub_key, en_res)
    text = json.loads(de_res)
    print(text)
