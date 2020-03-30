### 一、安装YUM Repo
- 1.由于CentOS 的yum源中没有mysql，需要到mysql的官网下载yum repo配置文件。
```
wget https://dev.mysql.com/get/mysql57-community-release-el7-9.noarch.rpm
```
- 2、然后进行repo的安装：
```
rpm -ivh mysql57-community-release-el7-9.noarch.rpm
```
- 3.进入到/etc/yum.repos.d/目录下就可以进行安装了 

```
yum install mysql-server
```

- 4、启动msyql：
```
systemctl start mysqld #启动MySQL
```

- 5、获取安装时的临时密码（在第一次登录时就是用这个密码）：
```
grep 'temporary password' /var/log/mysqld.log
```

- 6、倘若没有获取临时密码(一般按上述步骤应该会有)，则删除原来安装过的mysql残留的数据
```
rm -rf /var/lib/mysql
```

- 7.再启动mysql
```
systemctl start mysqld #启动MySQL
```

### 二、登录：
- 1、方式一（已验证）：
```
mysql -u root -p
```

- 然后输入密码（刚刚获取的临时密码）

- 2、方式二（未验证）：
```
vim /etc/my.cnf(注：windows下修改的是my.ini)
```

- 在文档内搜索mysqld定位到[mysqld]文本段：

- 在[mysqld]后面任意一行添加“skip-grant-tables”用来跳过密码验证
- 登录成功后修改密码


### 三.查看 mysql 初始的密码策略，

```
SHOW VARIABLES LIKE 'validate_password%';
```

```
输入修改语句 “ ALTER USER 'root'@'localhost' IDENTIFIED BY '123456'; ” 可以看到修改成功，表示密码策略修改成功了！！！

3.5、注：在默认密码的长度最小值为 4 ，由 大/小写字母各一个 + 阿拉伯数字一个 + 特殊字符一个，

只要设置密码的长度小于 3 ，都将自动设值为 4 ，

3.6、关于 mysql 密码策略相关参数；

1）、validate_password_length  固定密码的总长度；

2）、validate_password_dictionary_file 指定密码验证的文件路径；

3）、validate_password_mixed_case_count  整个密码中至少要包含大/小写字母的总个数；

4）、validate_password_number_count  整个密码中至少要包含阿拉伯数字的个数；

5）、validate_password_policy 指定密码的强度验证等级，默认为 MEDIUM；

关于 validate_password_policy 的取值：

LOW：只验证长度；

1/MEDIUM：验证长度、数字、大小写、特殊字符；

2/STRONG：验证长度、数字、大小写、特殊字符、字典文件；

6）、validate_password_special_char_count 整个密码中至少要包含特殊字符的个数；

```

### 四、修改密码
- 1、方式一（已验证）：
```
ALTER USER 'root'@'localhost' IDENTIFIED BY '@abcd123456'; 
```

- 2、方式二（未验证）
```
set password=password("yourpassword"); 
```

### 五、开启远程控制

- MySQL默认是没有开启远程控制的，必须添加远程访问的用户，即默认是只能自己访问，别的机器是访问不了的。
```
use mysql
修改user表中的Host:   update user set Host='%' where User='root';  
```

- 说明： % 代表任意的客户端,可替换成具体IP地址。

- 最后刷新一下：flush privileges;


###  六、其他配置

```
1、设置安全选项：

mysql_secure_installation
2、关闭MySQL

systemctl stop mysqld 
3、重启MySQL

systemctl restart mysqld 
4、查看MySQL运行状态

systemctl status mysqld 
5、设置开机启动

systemctl enable mysqld 
6、关闭开机启动

systemctl disable mysqld 
7、配置默认编码为utf8：

vi /etc/my.cnf #添加 [mysqld] character_set_server=utf8 init_connect='SET NAMES utf8'

其他默认配置文件路径： 

配置文件：/etc/my.cnf 日志文件：/var/log//var/log/mysqld.log 服务启动脚本：/usr/lib/systemd/system/mysqld.service socket文件：/var/run/mysqld/mysqld.pid
8、查看版本

select version();
```