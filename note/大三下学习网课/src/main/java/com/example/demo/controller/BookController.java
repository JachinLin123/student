package com.example.demo.controller;

import com.example.demo.data.domain.Book;
import com.example.demo.service.book.BookService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

/**
 * Created by litdwg on 2020/3/3 16:51
 */
@RestController
public class BookController {
    @Autowired
    BookService bookService;
    @GetMapping("/books")
    public List<Book> getall(String name){
        return bookService.list(name);
    }

    @PostMapping("/books")
    public Book insert(Book book){
        return  bookService.create(book);
    }

}
