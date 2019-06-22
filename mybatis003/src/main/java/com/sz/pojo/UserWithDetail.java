package com.sz.pojo;

public class UserWithDetail extends User {

    private UserDetail userDetail;

    public void setUserDetail(UserDetail userDetail) {
        this.userDetail = userDetail;
    }

    @Override
    public String toString() {
        return "User{" +
                "uid=" + getUid() +
                ", phone='" + getPhone() + '\'' +
                ", password='" + getPassword() + '\'' +
                ", createDate='" + getCreateDate()+ '\'' +
                ", status=" + getStatus()+
                '}'+"UserWithDetail{" +
                "userDetail=" + userDetail +
                '}';
    }

    public UserDetail getUserDetail(){
        return userDetail;
    }
}
