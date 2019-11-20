# -*- coding: utf-8 -*-
import scrapy


class PeopleSpider(scrapy.Spider):
    name = 'people'
    allowed_domains = ['http://www.people.com.cn']
    start_urls = ['http://http://www.people.com.cn/']
    base_url = ""
    

    def parse(self, response):
        pass
