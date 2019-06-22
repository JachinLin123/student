package com.sz;

import com.sz.mapper.UsersMapper;
import com.sz.pojo.UserDetail;
import com.sz.pojo.UserWithDetail;
import com.sz.util.MybatisUtil;
import org.apache.ibatis.session.SqlSession;
import org.junit.Test;

public class TestResult {


    @Test
    public void m1(){
        SqlSession sqlSession = MybatisUtil.getSession();

        UsersMapper mapper = sqlSession.getMapper(UsersMapper.class);

        UserWithDetail userWithDetail = mapper.queryById(1);

        System.out.println(userWithDetail);

        sqlSession.close();
    }

    @Test
    public void m2(){
        SqlSession sqlSession = MybatisUtil.getSession();

        UsersMapper mapper = sqlSession.getMapper(UsersMapper.class);

        UserWithDetail userWithDetail = mapper.queryByIdByStep(1);

        System.out.println(userWithDetail);

        sqlSession.close();
    }
}
