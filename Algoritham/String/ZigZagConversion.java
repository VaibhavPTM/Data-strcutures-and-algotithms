 // ZigZagConversion
 // Link : https://leetcode.com/problems/zigzag-conversion/

public class ZigZagConversion {

    public static void main(String[] args) {
        System.out.println(convert("PAYPALISHIRING",4));
    }
    public static String convert(String s, int numRows) {
        int len=s.length();
        if(numRows==1 || len<=numRows)
            return s;
        char c[]=new char[len];
        int pos=0, count=0;
        boolean goinup;
        for(int x=0; x<numRows; x++) {
            goinup=true;
            pos=x;
            while(pos<len) {
                c[count]=s.charAt(pos);
                pos+=(x==0||x==numRows-1)?(numRows-1)*2:goinup?((numRows-x-1)*2):x*2;
                goinup=!goinup;
                ++count;
            }
        }
        return String.valueOf(c);
    }
}