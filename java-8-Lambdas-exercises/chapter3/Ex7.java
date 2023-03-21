package chapter3;

import static chapter3.Ex6.countLowercaseLetters;

public class Ex7 {
    public static void main(String[] args) {
        
    }

    public static Optional<String> mostLowercaseString(List<String> strings) {
        return strings.stream()
                      .max(Comparator.comparingInt(StringExercises::countLowercaseLetters));
    }
}
