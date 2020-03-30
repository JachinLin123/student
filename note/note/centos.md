http://ac.scmor.com/



http://ncre.neea.edu.cn/html1/report/1508/290-1.htm



curl "https://bootstrap.pypa.io/get-pip.py" -o "get-pip.py"
python get-pip.py

pip install --upgrade pip
pip install shadowsocks
vim /etc/shadowsocks.json
{
  "server": "0.0.0.0",
"local_address": "127.0.0.1",
"local_port": 1080,
"port_password":{ "8080":"JachinLin",
                  "8081":"JachinLin"},
"timeout": 600,
"method": "chacha20"
  
}

aes-256-cfb


vim /etc/systemd/system/shadowsocks.service
[Unit]
Description=Shadowsocks

[Service]
TimeoutStartSec=0
ExecStart=/usr/bin/ssserver -c /etc/shadowsocks.json

[Install]
WantedBy=multi-user.target

systemctl enable shadowsocks
systemctl start shadowsocks
systemctl status shadowsocks -l

firewall-cmd --zone=public --add-port=8080/tcp --permanent

firewall-cmd --zone=public --add-port=8081/tcp --permanent

firewall-cmd --reload


测速
https://tools.ipip.net/ping.php

节点
https://tool.ssrshare.us/free_ssr
https://jiji.im/signin
https://jiji.im/user/node
https://jiji.im/user?ran=0.42699107700018857

工具
http://tool.imiku.me 


https://github.com/233boy/v2ray/wiki/V2RayN%E4%BD%BF%E7%94%A8%E6%95%99%E7%A8%8B


v2ray配置教程
https://toutyrater.github.io/


https://www.office.com/?auth=2&home=1


https://blog.csdn.net/jinguangliu/article/details/78067768


