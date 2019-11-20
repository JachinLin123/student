package exp6_itmumu;

public class Bank {
    public int savedmoney;
    public int year;
    public double interest;
    public double interestRate = 0.29;

    /**
     * 在父类构造一个计算利息的方法
     *
     * @return
     */
    public double computerInterest() {
        interest = savedmoney * year * interestRate;
        return interest;
    }

    /**
     * 设置利率的方法
     *
     * @param Rate
     */
    public void setInterestRate(double Rate) {
        interestRate = Rate;
    }
}

class ConstructionBank extends Bank {
    public double year;

    /**
     * 重写父类的方法
     *
     * @return
     */
    @Override
    public double computerInterest() {
        super.year = (int) year;
        double r = year - (int) year;
        int day = (int) (r * 1000);
        double yearInterest = super.computerInterest();
        double dayInterest = savedmoney * 0.0001 * day;
        interest = yearInterest + dayInterest;
        System.out.printf("%d元存在建设银行%d年零%d天的利息:%f元\n",
                savedmoney, super.year, day, interest);
        return interest;
    }

}

class BankOfDalian extends Bank {
    public double year;

    /**
     * 重写父类的方法
     *
     * @return
     */
    @Override
    public double computerInterest() {
        super.year = (int) year;
        double r = year - (int) year;
        int day = (int) (r * 1000);
        double yearInterest = super.computerInterest();
        double dayInterest = day * 0.00012 * savedmoney;
        interest = dayInterest + yearInterest;
        System.out.printf("%d元存在大连银行%d年零%d天的利息:%f元\n",
                savedmoney, super.year, day, interest);
        return interest;
    }
}

class CommercialBank extends Bank {
    public double year;

    /**
     * 重写父类的方法
     *
     * @return
     */
    @Override
    public double computerInterest() {
        super.year = (int) year;
        double r = year - (int) year;
        int day = (int) (r * 1000);
        double yearInterest = super.computerInterest();
        double dayInterest = day * 0.00015 * savedmoney;
        interest = dayInterest + yearInterest;
        System.out.printf("%d元存在商业银行%d年零%d天的利息:%f元\n",
                savedmoney, super.year, day, interest);
        return interest;
    }
}