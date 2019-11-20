import requests
import json


url = 'http://appjph.jiupaicn.com/app/content/recommend_pc/list?deviceId=888&type=1&page=1&pageSize=15&_=1485163767294'
webdata = requests.get(url).text

data = json.loads(webdata)
news = data['resultData']

for n in news:
	title = n['title']
	name = n['memberName']
	News_url = 'http://jphao.jiupaicn.com/index.php?m=content&c=jiupaihao&a=article&' + '&id=' + n['id'] + '&memberId=' + n['memberId']
	print(title,name,News_url)