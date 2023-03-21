# hash
mac 计算文件的hash的命令: `shasum filename`

```txt
ty@ty-mba:~/Desktop/xmind % shasum LINUX.xmind                         
446aaf8467b81b52273a5611c6a1b56f370b522a  LINUX.xmind
```
基本上两个文件的hash值不会一致。所以用来做校验非常好。（hash一致且能产生破坏的概率可以说是0）

## hash加密的具体算法
* MD5
* SHA
* HMAC
  
# KDFs(key derivation functions)

根据WikiPedia的定义：
> In cryptography, a key derivation function (KDF) is a cryptographic algorithm that derives one or more secret keys from a secret value such as a master key, a password, or a passphrase using a pseudorandom function (which typically uses a cryptographic hash function or block cipher). KDFs can be used to stretch keys into longer keys or to obtain keys of a required format, such as converting a group element that is the result of a Diffie–Hellman key exchange into a symmetric key for use with AES. Keyed cryptographic hash functions are popular examples of pseudorandom functions used for key derivation.
>

作用：增加密钥的复杂性，增加破解的时间。

# 对称加密

对称加密的加密和解密使用同一个密钥。

加密解密过程：明文->密钥加密->密文，密文->密钥解密->明文。

## 密码加密的流程
```txt
passphrase               plain text
   |                        |
   |                        |
  KDFs()                    |
   |                        |
   |                        |
  key  -------------------  |
                |
                |
            encrypted 
```

# 非对称加密RSA

非对称加密算法需要两个密钥：公开密钥(publickey) 和私有密钥(privatekey) 。

> 如果用公开密钥对数据进行加密，只有用对应的私有密钥才能解密。 
> 
> 如果用私有密钥对数据进行加密，只有用对应的公开密钥才能解密。

ssh 的加密传输就是这么工作的。

