# -*- coding: utf-8 -*-

# Define your item pipelines here
#
# Don't forget to add your pipeline to the ITEM_PIPELINES setting
# See: https://docs.scrapy.org/en/latest/topics/item-pipeline.html
import scrapy
import os
from scrapy.pipelines.images import ImagesPipeline

class DouyuPipeline(ImagesPipeline):

    def get_media_requests(self, item, info):
        image_link = item['imagelink']
        yield scrapy.Request(image_link)

    def item_completed(self, results, item, info):
        # print (results)
        # print("*" * 30)
        image_path = [x["path"] for ok, x in results if ok]
        images_store  = "E:/vscode/py/Douyu/images/"
        os.rename(images_store + image_path[0], images_store + item["nickname"] + ".jpg")
        return item
        


    # def process_item(self, item, spider):
    #     return item
