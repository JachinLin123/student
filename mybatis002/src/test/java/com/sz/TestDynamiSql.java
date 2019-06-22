package com.sz;


import com.sz.mapper.AdressesMapper;
import com.sz.pojo.Addresses;
import com.sz.util.MybatisUtil;
import org.apache.ibatis.session.SqlSession;
import org.junit.Test;

import java.util.ArrayList;
import java.util.List;

public class TestDynamiSql {

    @Test
    public void m1(){

        //按照Id查询
        SqlSession sqlSession = MybatisUtil.getSession();

        AdressesMapper mapper = sqlSession.getMapper(AdressesMapper.class);

        Addresses addresses = mapper.queryByAdrId(11);

        System.out.println(addresses);

        sqlSession.close();


    }

    @Test
    public void m2(){


        SqlSession sqlSession = MybatisUtil.getSession();

        AdressesMapper mapper = sqlSession.getMapper(AdressesMapper.class);

        Addresses addresses = new Addresses();
        addresses.setAddrId(12);

        addresses.setCity("aa");

        addresses.setCountry("23");

        addresses.setState("54353");

        addresses.setStreet("535");

       // addresses.setZip("123");

        mapper.update(addresses);

        sqlSession.commit();

        sqlSession.close();

    }
    @Test
    public void m3(){


        SqlSession sqlSession = MybatisUtil.getSession();

        AdressesMapper mapper = sqlSession.getMapper(AdressesMapper.class);

        //List<Addresses> addresses = mapper.queryByCountryCity("like","Bolish");

        List<Addresses> addresses = mapper.queryByCountryCity("like",null);

        System.out.println(addresses);

        sqlSession.close();


    }

    @Test
    public void m4(){


        SqlSession sqlSession = MybatisUtil.getSession();

        AdressesMapper mapper = sqlSession.getMapper(AdressesMapper.class);

        Addresses addresses = new Addresses();

        addresses.setCountry("like");

        addresses.setState("fan");

        List<Addresses> query = mapper.query(addresses);

        System.out.println(query);

        sqlSession.commit();

        sqlSession.close();


    }

    @Test
    public void m5(){


        SqlSession sqlSession = MybatisUtil.getSession();

        AdressesMapper mapper = sqlSession.getMapper(AdressesMapper.class);

        Addresses addresses = new Addresses();

        addresses.setCountry("like");

        //addresses.setState("fan");

        List<Addresses> query = mapper.queryTrim(addresses);

        System.out.println(query);

        sqlSession.commit();

        sqlSession.close();


    }

    @Test
    public void m6(){


        SqlSession sqlSession = MybatisUtil.getSession();

        AdressesMapper mapper = sqlSession.getMapper(AdressesMapper.class);

        List<Integer> l = new ArrayList<>();

        l.add(1);

        l.add(2);

        l.add(3);

       // l.add(3);

       List<Addresses> addresses = mapper.queryByIds(l);

        System.out.println(addresses);

        sqlSession.commit();

        sqlSession.close();


    }
    @Test
    public void m7(){
        SqlSession sqlSession = MybatisUtil.getSession();
        AdressesMapper mapper = sqlSession.getMapper(AdressesMapper.class);
        //方案一通过%加入
        //List<Addresses> addresses =  mapper.queryLike("%L%");
        //方案二通过函数连接
        //List<Addresses> addresses =  mapper.queryLike("L");
        //方案三通过bind标签重新进行绑定
        List<Addresses> addresses =  mapper.queryLike("L");
        System.out.println(addresses);
        sqlSession.commit();
        sqlSession.close();
    }

    @Test
    public void m8(){
        SqlSession sqlSession = MybatisUtil.getSession();
        AdressesMapper mapper = sqlSession.getMapper(AdressesMapper.class);
        /*
        同一会话当中才有用
        二级--一级--数据库
         */
        List<Addresses> addresses =  mapper.listAll();
        System.out.println(addresses);
        sqlSession.commit();
        sqlSession.close();
    }

    @Test
    public void m9(){
        SqlSession sqlSession = MybatisUtil.getSession();
        AdressesMapper mapper = sqlSession.getMapper(AdressesMapper.class);
        /*
        【缓存失效方式一】如果查询进行的增删改的行为，将会导致缓存失效
         */
        List<Addresses> addresses =  mapper.listAll();
        Addresses a = new Addresses();

        a.setAddrId(3);

        a.setCity("aa");

        a.setCountry("23");

        a.setState("54353");

        a.setStreet("535");
        // addresses.setZip("123");
        mapper.update(a);
        List<Addresses> addresses2 =  mapper.listAll();
        sqlSession.commit();
        sqlSession.close();
    }

    @Test
    public void m10(){
        SqlSession sqlSession = MybatisUtil.getSession();
        AdressesMapper mapper = sqlSession.getMapper(AdressesMapper.class);
        /*
        【缓存失效方式一】如果查询进行的增删改的行为，将会导致缓存失效
         */
        List<Addresses> addresses =  mapper.listAll();

        //强制清空缓存,清空所有
        sqlSession.clearCache();
        List<Addresses> addresses2 =  mapper.listAll();
        sqlSession.commit();
        sqlSession.close();
    }

    @Test
    public void m11(){
        SqlSession sqlSession = MybatisUtil.getSession();
        AdressesMapper mapper = sqlSession.getMapper(AdressesMapper.class);
        /*
        【缓存失效方式一】如果查询进行的增删改的行为，将会导致缓存失效
         */
        List<Addresses> addresses =  mapper.listAll();

        //强制清空缓存,清空所有
        sqlSession.flushStatements();
        List<Addresses> addresses2 =  mapper.listAll();
        sqlSession.commit();
        sqlSession.close();
    }
//二级缓存实验
    @Test
    public void m12(){
        SqlSession sqlSession = MybatisUtil.getSession();
        SqlSession sqlSession2 = MybatisUtil.getSession();
        AdressesMapper mapper = sqlSession.getMapper(AdressesMapper.class);
        AdressesMapper mapper2 = sqlSession2.getMapper(AdressesMapper.class);
        mapper.listAll();
        sqlSession.close();
        mapper2.listAll();
        sqlSession2.close();
}
}
