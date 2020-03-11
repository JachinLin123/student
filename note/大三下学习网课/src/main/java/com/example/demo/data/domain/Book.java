package com.example.demo.data.domain;

import com.baomidou.mybatisplus.annotation.TableName;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

/**
 * Created by litdwg on 2020/3/3 16:39
 */
@Data
@NoArgsConstructor
@AllArgsConstructor
@TableName("t_article")
public class Book {
    int id;
    String title;
    String content;
}
