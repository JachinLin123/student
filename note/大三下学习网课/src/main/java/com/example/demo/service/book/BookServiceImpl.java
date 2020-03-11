package com.example.demo.service.book;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.example.demo.data.domain.Book;
import com.example.demo.data.mapper.BookMapper;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

/**
 * Created by litdwg on 2020/3/3 16:46
 */
@Service
public class BookServiceImpl implements BookService {

    @Autowired
    BookMapper bookMapper;

    @Override
    public Book create(Book book) {
        bookMapper.insert(book);
        return book;
    }

    @Override
    public boolean delete(int id) {
        bookMapper.deleteById(id);
        return true;
    }

    @Override
    public Book update(Book book) {
        bookMapper.updateById(book);
        return book;
    }

    @Override
    public List<Book> list(String name) {
        return bookMapper.selectList(null);
    }
}
