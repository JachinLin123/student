/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package cn.itmumu.dao;

import cn.itmumu.pojo.User;

/**
 *
 * @author admin
 */
public interface UserDao {
    /**
     * 
     * @param username
     * @param password
     * @return 
     */
    public abstract boolean login(String username, String password);
    /**
     * 
     * @param user 
     */
    public abstract void regist(User user);
    
}
