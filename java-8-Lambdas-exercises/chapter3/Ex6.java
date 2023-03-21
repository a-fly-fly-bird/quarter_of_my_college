package chapter3;
public class Ex6 {
    public static void main(String[] args) {
        System.out.println(countLowerCase("Hello World"));
    }

    private static int countLowerCase(String s){
        /**
         * 把数组转化为Stream的两种方法：
         * 1. Stream.of()
         * 2. Arrays.stream()
         */
        // return (int) Arrays.stream(s.toCharArray())
        //              .filter(c -> Character.isLowerCase(c))
        //              .count();
        /**
         * 标准答案
         */
        return (int) s.chars()
                           .filter(Character::isLowerCase)
                           .count();
    }

    
}
