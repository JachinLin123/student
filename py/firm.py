'''
@admin jachinlin

'''
import json
import requests
from lxml import etree

'''
获取数据

'''
def getOnePage(n):

    # r = requests.get("https://api.github.com/events")

    url = 'http://maoyan.com/board/{}'.format(n)
    # 反爬 伪装浏览器
    user_agent = 'Mozilla/4.0 (compatible; MSIE 5.5; Windows NT)'
    header = { 'User-Agent' : user_agent }

    r = requests.get(url, headers=header)

    return r.text


'''
格式化数据
'''
def parse(text):

    # 初始化 标准化
    html = etree.HTML(text)

    # 提取需要的信息 需要写xpath语法
    names = html.xpath('//div[@class="movie-item-info"]/p[@class="name"]/a/@title')

    releasetime = html.xpath('//p[@class="releasetime"]/text()')
    # print(names)
    item = {}
    for name, releasetime in zip(names, releasetime):
        # print(names, releasetime)
        # 字典
        item['name'] = name
        item['releasetime'] = releasetime
        # 生成器
        yield item



'''
保存数据格式
'''
def save2File(data):
    with open('movie.json', 'a', encoding='utf-8') as f:
        # 把字典转化为字符串
        data = json.dumps(data, ensure_ascii=False) + ',\n'

        f.write(data)

def run():
    for n in range(1, 20):

        text = getOnePage(n)
        items = parse(text)
        for item in items:
            save2File(item)



if __name__ == "__main__":
    
    run()







