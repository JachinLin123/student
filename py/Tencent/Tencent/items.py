# -*- coding: utf-8 -*-

# Define here the models for your scraped items
#
# See documentation in:
# https://docs.scrapy.org/en/latest/topics/items.html

import scrapy


class TencentItem(scrapy.Item):
    # define the fields for your item here like:
    # 定义您想要爬取的字段
    positionName = scrapy.Field()

    positionLink = scrapy.Field()

    positionType = scrapy.Field()

    positionNumber = scrapy.Field()

    workLocation = scrapy.Field()

    publishTime = scrapy.Field()
    
