### 1. 事先准备jdk和tomcat，tomcat也可以从官网上下载

```
1.解压

tar -zvxf jdk-8u191-linux-x64.tar.gz

2.移动到/usr/local/java,便于管理

mv jdk-8u191-linux-x64.tar.gz /usr/local/java

3. 添加环境变量

vim /etc/profile.d/java.sh

4. 复制下面几句话

export JAVA_HOME=/usr/local/java/jdk1.8.0_191
export CLASS_PATH=".:$JAVA_HOME/jre/lib:$JAVA_HOME/lib"
export PATH=$PATH:$JAVA_HOME/bin

5.让刚才设置的环境变量生效

source /etc/proflie

6. 验证是否成功

java -version


```

### 接下来就是tomcat安装

```
1.download the tomcat 

wget http://mirror.bit.edu.cn/apache/tomcat/tomcat-8/v8.5.31/bin/apache-tomcat-8.5.31.tar.gz
tar xf apache-tomcat-8.5.31.tar.gz -C /usr/local/

2. back the struct

cd /usr/local/

3. rename

ln -sv apache-tomcat-8.5.31 tomcat

4. set the enviroment

vim /etc/profile.d/tomcat.sh

5. copy the text

CATALINA_BASE=/usr/local/tomcat
PATH=$CATALINA_BASE/bin:$PATH
export PATH CATALINA_BASE

6.make it effects

source /etc/profile.d/tomcat.sh

7. start the tomcat

catalina.sh start
　　
```
