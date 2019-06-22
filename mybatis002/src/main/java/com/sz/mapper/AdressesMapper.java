package com.sz.mapper;

import com.sz.pojo.Addresses;
import org.apache.ibatis.annotations.Param;

import java.util.List;

public interface AdressesMapper {

    Addresses queryByAdrId(Integer id);

    List<Addresses> queryByCountryCity(@Param("country") String country,@Param("city") String city);

    int update(Addresses addresses);

    List<Addresses> query(Addresses addresses);

    List<Addresses> queryTrim(Addresses addresses);

    List<Addresses> queryByIds(List<Integer> list);

    List<Addresses> queryLike(@Param("city") String city);

    List<Addresses> listAll();
}
