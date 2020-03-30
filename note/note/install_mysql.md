# 基本步骤

* 1.加入系统path
* 2.目录创建data文件与my.ini配置文件
* 3.修改My.ini文件
```
[mysqld]
# 设置3306端口
port=3306
# 设置mysql的安装目录
basedir=C:\mysql\mysql-8.0.17-winx64
# 设置mysql数据库的数据的存放目录
datadir=C:\mysql\mysql-8.0.17-winx64\data
# 允许最大连接数
max_connections=200
# 允许连接失败的次数。
max_connect_errors=10
# 服务端使用的字符集默认为utf8mb4
character-set-server=utf8
# 创建新表时将使用的默认存储引擎
default-storage-engine=INNODB
# 默认使用“mysql_native_password”插件认证
#mysql_native_password
default_authentication_plugin=mysql_native_password
[mysql]
# 设置mysql客户端默认字符集
default-character-set=utf8
[client]
# 设置mysql客户端连接服务端时默认使用的端口
port=3306
default-character-set=utf8
```
* 4.输入：mysqld --initialize-insecure
* 5.输入：mysqld --install
* 6.输入:net start mysql
* 7.登入:mysql -uroot -p
* 8.修改密码:ALTER USER 'root'@'localhost' IDENTIFIED BY '新密码';