import subprocess
import os
from rich.console import Console
import pyfiglet

console = Console()


class CA:
    def __init__(self, dir='./'):
        self.dir = dir
        self.private_key_path = os.path.join(self.dir, 'private/', 'cakey.pem')
        self.ca_path = os.path.join(self.dir, 'cacert.pem')
        self.csr_path = os.path.join(self.dir, 'csr/intermediate.csr.pem')
        self.create_dir_structure()
        self.create_files()

    def create_dir_structure(self):
        dirs = ['private', 'certs', 'newcerts']
        [subprocess.run(['mkdir', os.path.join(self.dir, dir)]) for dir in dirs]
        console.print('目录结构创建成功', style="bold red")

    def create_files(self):
        subprocess.run(['touch', os.path.join(self.dir, "serial")])
        subprocess.run(['touch', os.path.join(self.dir, 'index.txt')])
        console.print('文件创建成功', style="bold red")

    def gen_rsa_priv(self):
        try:
            return_code = subprocess.run(
                ['openssl', 'genrsa', '-out', self.private_key_path, str(4096)])
            console.print('创建私钥成功', style="bold red")
        except:
            console.print('创建私钥失败', style="bold red")

    def get_priv_details(self):
        # return_code = subprocess.run('openssl rsa -in rsa_private.key -noout -text'.split(sep=" "))
        return_code = subprocess.run(
            ['openssl', 'rsa', '-in', self.private_key_path, '-noout', '-text'])
        console.print(return_code, style="bold blue")
    
    def gen_root_certificate(self, conf_path):
        subprocess.run(['openssl', 'req', '-new', '-x509', '-days', '3650',
                                     '-config', conf_path, '-extensions', 'v3_ca', '-key', self.private_key_path, '-out', self.ca_path])
        console.print('Root CA Certificate 生成成功', style="bold blue")

    def gen_intermediate_csr(self, conf_path):
        subprocess.run(
            ['openssl', 'req', '-new', '-sha256', '-config', conf_path, '-key', self.private_key_path, '-out', self.csr_path])
        console.print('CSR创建成功', style="bold blue")

    def sign(self, conf_path, csr_path, inter_ca_path):
        subprocess.run(['openssl', 'ca', '-config', conf_path, '-extensions', 'v3_intermediate_ca', '-days', '2650', '-notext', '-batch', '-in', csr_path, '-out', inter_ca_path])
        console.print('签名成功', style="bold blue")

    def verify_ca(self, a, judge):
        result = subprocess.run(['openssl', 'verify', '-CAfile', a, judge])
        console.print(result, style="bold blue")

    def create_ca_chain(self, a, b, out_path):
        result = subprocess.run(['cat', a, b], stdout=subprocess.PIPE) 
        res = result.stdout.decode('utf-8')  # 利用res将结果输出到文件
        with open(out_path, 'w+') as file:
            file.write(res)
        console.print('chain 生成成功', style="bold blue")

if __name__ == '__main__':
    ca = CA('/root/catkin_ws/tls')
    ca.gen_rsa_priv()
    ca.get_priv_details()
    ca.gen_root_certificate('/root/catkin_ws/tls/openssl.cnf')

    inter_ca = CA('/root/catkin_ws/tls/intermediate')
    inter_ca.gen_rsa_priv()
    inter_ca.get_priv_details()
    inter_ca.gen_intermediate_csr('/root/catkin_ws/tls/intermediate/openssl.cnf')

    ca.sign('/root/catkin_ws/tls/openssl.cnf', '/root/catkin_ws/tls/intermediate/csr/intermediate.csr.pem', '/root/catkin_ws/tls/intermediate/intermediate.cacert.pem')
    inter_ca.verify_ca('/root/catkin_ws/tls/cacert.pem', '/root/catkin_ws/tls/intermediate/intermediate.cacert.pem')
    inter_ca.create_ca_chain('/root/catkin_ws/tls/intermediate/intermediate.cacert.pem', '/root/catkin_ws/tls/cacert.pem', '/root/catkin_ws/tls/intermediate/certs/ca-chain-bundle.cert.pem')