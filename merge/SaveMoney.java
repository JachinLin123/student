package exp6_itmumu;

/**
 * @author it_mumu
 */
public class SaveMoney {
    public static void main(String[] args) {
        /**
         * 存入的金额
         */
        int amount = 8000;
        /**
         * 创建一个建设银行对象
         */
        ConstructionBank bank1 = new ConstructionBank();
        bank1.savedmoney = amount;
        bank1.year = 8.236;
        bank1.setInterestRate(0.035);
        double interest1 = bank1.computerInterest();
        /**
         * 创建一个大连银行对象
         */
        BankOfDalian bank2 = new BankOfDalian();
        bank2.savedmoney = amount;
        bank2.year = 8.236;
        bank2.setInterestRate(0.035);
        double interest2 = bank2.computerInterest();
        /**
         * 创建一个商业银行对象
         */
        CommercialBank bank3 = new CommercialBank();
        bank3.savedmoney = amount;
        bank3.year = 8.236;
        bank3.setInterestRate(0.035);
        double interest3 = bank3.computerInterest();
        System.out.printf("建设和大连两个银行的利息相差%f元\n", interest2 - interest1);
    }
}
