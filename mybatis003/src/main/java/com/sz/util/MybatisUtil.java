package com.sz.util;

import org.apache.ibatis.io.Resources;
import org.apache.ibatis.session.*;

import java.io.IOException;
import java.io.InputStream;
import java.sql.Connection;

public class MybatisUtil {

    private static SqlSessionFactory sqlSessionFactory;

    static{
        String resource = "mybatis.cfg.xml";
        InputStream in = null;
        try{
            in = Resources.getResourceAsStream(resource);
            sqlSessionFactory = new SqlSessionFactoryBuilder().build(in);
        }catch (IOException e){
            e.printStackTrace();
        }finally {
            if(in !=null){
                try {
                    in.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }
    }


    public static SqlSession getSession(){
        return sqlSessionFactory.openSession();
    }
}
