package com.sz.mapper;

import com.sz.pojo.UserWithDetail;
import org.apache.ibatis.annotations.Param;

public interface UsersMapper {

    UserWithDetail queryById(@Param("uid")Integer id);

    UserWithDetail queryByIdByStep(@Param("uid")Integer id);
}
