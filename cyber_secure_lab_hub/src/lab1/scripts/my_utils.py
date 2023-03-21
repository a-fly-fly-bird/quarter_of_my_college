import rsa
import os
import hashlib
import pyfiglet
import fire

from cryptography.fernet import Fernet
'''
哈希单向
'''
def hash(text):
    md5 = hashlib.md5()
    md5.update(text.encode('utf-8'))
    res = md5.hexdigest().encode('utf-8')
    print(type(res), res)
    return res

'''
  对称加密
'''


def gen_fernet_key():
    key = Fernet.generate_key()
    path = './key/'
    public_file = os.path.join(path, 'fernet_key.key')
    with open(public_file, "wb+") as key_file:
        key_file.write(key)
    print('保存fernet_key成功')


def read_fernet_key(file_path):
    with open(file_path, 'rb') as f:
        fernet_key = f.read()
    return fernet_key


def fernet_encrypt(obj: str, key):
    f = Fernet(key)
    obj = obj.encode()
    encrypted = f.encrypt(obj)
    return encrypted


def fernet_decrypt(obj, key):
    f = Fernet(key)
    decrypted = f.decrypt(obj)
    return decrypted


'''
  非对称加密
'''


def create_key():
    publicKey, privateKey = rsa.newkeys(512)
    path = './key/'
    public_file = os.path.join(path, 'publicKey.key')
    private_file = os.path.join(path, 'privateKey.key')
    with open(public_file, 'wb+') as f:
        pk = rsa.PublicKey.save_pkcs1(publicKey, format='PEM')
        f.write(pk)
        print('保存公钥成功')
    with open(private_file, 'wb+') as f:
        pk = rsa.PrivateKey.save_pkcs1(privateKey, format='PEM')
        f.write(pk)
        print('保存私钥成功')


def read_public_key(file_path):
    with open(file_path, 'rb') as f:
        public_file = f.read()
        # print(type(public_file), public_file)
        pubkey = rsa.PublicKey.load_pkcs1(keyfile=public_file)
        # pubkey = f.read().replace('-----BEGIN RSA PUBLIC KEY-----\n', '')
        # pubkey = pubkey.replace('-----END RSA PUBLIC KEY-----\n', '')
    return pubkey


def read_private_key(file_path):
    with open(file_path, 'rb') as f:
        private_file = f.read()
        # print(type(private_file), private_file)
        privkey = rsa.PrivateKey.load_pkcs1(keyfile=private_file)
        # privkey = f.read().replace('-----BEGIN RSA PRIVATE KEY-----\n', '')
        # privkey = privkey.replace('-----END RSA PRIVATE KEY-----\n', '')
    return privkey


def rsa_encrypt(obj: str, pub_key):
    encrypted_msg = obj.encode()
    encrypted_msg = rsa.encrypt(encrypted_msg, pub_key)
    return encrypted_msg


def rsa_decrypt(obj, priv_key):
    decMessage = rsa.decrypt(obj, priv_key)
    return decMessage


class Crypt(object):
    def gen_fernet_key(self):
        return gen_fernet_key()
    def create_key(self):
        create_key()
    def print_keys(self):
        file_path = './key/publicKey.key'
        print(read_public_key(file_path))
        file_path = './key/privateKey.key'
        print(read_private_key(file_path))
    def print_key(self):
        file_path = './key/fernet_key.key'
        print(read_fernet_key(file_path))

if __name__ == '__main__':
    result = pyfiglet.figlet_format("Cryptal -- Core")
    print(result)

    fire.Fire(Crypt)

    # create_key()
    # file_path = './key/publicKey.key'
    # print(read_public_key(file_path))
    # file_path = './key/privateKey.key'
    # print(read_private_key(file_path))

    # gen_fernet_key()
    # file_path = './key/fernet_key.key'
    # print(read_fernet_key(file_path))
