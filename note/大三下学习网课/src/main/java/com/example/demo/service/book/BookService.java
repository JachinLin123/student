package com.example.demo.service.book;

import com.example.demo.data.domain.Book;

import java.util.List;

/**
 * Created by litdwg on 2020/3/3 16:44
 */
public interface BookService {
    public Book create(Book book);
    public boolean delete(int id);
    public Book update(Book book);
    public List<Book> list(String name);
}
