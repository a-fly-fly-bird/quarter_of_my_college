import subprocess
import os
from rich.console import Console
import pyfiglet

console = Console()

class CA:
    def __init__(self, dir='./keys/', private_key_filename='rsa_private.key', public_key_filename='rsa_public.key',         key_length=2048, self_cert_filename='cert.crt', server_signature_request_filename='server.csr', server_signed_ca_filename='server.crt'):
        self.dir = dir
        self.private_key_filename = private_key_filename
        self.public_key_filename = public_key_filename
        self.key_length = key_length
        self.private_key_path = os.path.join(
            self.dir, self.private_key_filename)
        self.public_key_path = os.path.join(
            self.dir, self.public_key_filename)
        self.self_cert_filename = self_cert_filename
        self.self_cert_path = os.path.join(self.dir, self.self_cert_filename)
        self.server_signature_request_filename = server_signature_request_filename
        self.server_signature_request_filepath = os.path.join(
            self.dir, self.server_signature_request_filename)
        self.server_signed_ca_filename = server_signed_ca_filename
        self.server_signed_ca_filepath = os.path.join(
            self.dir, self.server_signed_ca_filename)

    def gen_rsa_priv(self):
        return_code = subprocess.run(
            ['openssl', 'genrsa', '-out', self.private_key_path, str(self.key_length)])
        console.print(return_code, style="bold red")

    def gen_rsa_pub(self):
        return_code = subprocess.run(
            ['openssl', 'rsa', '-in', self.private_key_path, '-pubout', '-out', self.public_key_path])
        console.print(return_code, style="bold red")

    def check_priv_key_details(self):
        # return_code = subprocess.run('openssl rsa -in rsa_private.key -noout -text'.split(sep=" "))
        return_code = subprocess.run(
            ['openssl', 'rsa', '-in', self.private_key_path, '-noout', '-text'])
        console.print(return_code, style="bold blue")

    def self_signed_certificate(self):
        return_code = subprocess.run(['openssl', 'req', '-newkey', 'rsa:'+str(self.key_length), '-nodes',
                                     '-keyout', self.private_key_path, '-x509', '-days', '365', '-out', self.self_cert_path])
        console.print(return_code, style="bold blue")

    def slient_self_signed_certificate(self):
        return_code = subprocess.run(['openssl', 'req', '-newkey', 'rsa:'+str(self.key_length), '-nodes', '-keyout', self.private_key_path,
                                     '-x509', '-days', '365', '-out', self.self_cert_path, '-subj', "/C=CN/ST=GD/L=SZ/O=lucas/OU=dev/CN=China/emailAddress=abcgoogle.com"])
        console.print(return_code, style="bold blue")

    def signed_certificate_with_existing_priv_key(self):
        return_code = subprocess.run(['openssl', 'req', '-new', '-x509', '-days',
                                     '365', '-key', self.private_key_path, '-out', self.self_cert_path])
        console.print(return_code, style="bold blue")

    def gen_signature_request(self):
        return_code = subprocess.run(
            ['openssl', 'req', '-new', '-key', self.private_key_path, '-out', self.server_signature_request_filepath])
        console.print(return_code, style="bold blue")

    def slient_gen_signature_request(self):
        return_code = subprocess.run(
            ['openssl', 'req', '-new', '-key', self.private_key_path, '-out', self.server_signature_request_filepath, '-subj', "/C=UK/ST=LD/L=SZ/O=lucas/OU=dev/CN=China/emailAddress=abcgoogle.com"])
        console.print(return_code, style="bold blue")

    def check_signature_request_details(self):
        return_code = subprocess.run(
            ['openssl', 'req', '-noout', '-text', 'in', self.server_signature_request_filepath])
        console.print(return_code, style="bold blue")

    def gen_x509_ca(self):
        return_code = subprocess.run(['openssl', 'x509', '-req', '-days', '3650', '-in', self.server_signature_request_filepath,
                                     '-CA', self.self_cert_path, '-CAkey', self.private_key_path, '-CAcreateserial', '-out', self.server_signed_ca_filepath])
        console.print(return_code, style="bold purple")

    def check_ca_details(self):
        return_code = subprocess.run(
            ['openssl', 'x509', '-in', self.server_signed_ca_filepath, '-noout', '-text'])
        console.print(return_code, style="bold purple")

    # PKCS#12标准定义了个人身份信息（包括私钥、证书、各种秘密和扩展字段）的格式。p12 文件则是个人秘钥文件，可以只包含私钥，也可以包含证书和私钥。一般用于用户在不同设备间移动他们的个人身份信息。

    def refine_public_key_from_ca(self):
        path = os.path.join(self.dir, 'server_1.pem')
        outfile = open(path,'wb+')
        return_code = subprocess.Popen(
            ['openssl', 'x509', '-in', self.server_signed_ca_filepath, '-pubkey', '-noout'], stdout=outfile, shell=False)
        outfile.close()
        console.print(return_code, style="bold purple")

    def verify_ca(self):
        return_code = subprocess.Popen(['openssl', 'verify', '-CAfile', self.self_cert_path, self.server_signed_ca_filepath])
        console.print(return_code, style="bold purple")

if __name__ == '__main__':
    hello = pyfiglet.figlet_format("CA -- Module")
    print(hello)
    ca = CA()
    ca.gen_rsa_priv()
    ca.gen_rsa_pub()
    ca.check_priv_key_details()
    # ca.self_signed_certificate()
    ca.slient_self_signed_certificate()
    # ca.signed_certificate_with_existing_priv_key()
    ca.slient_gen_signature_request()
    ca.gen_x509_ca()
    ca.check_ca_details()
    ca.refine_public_key_from_ca()
    ca.verify_ca()