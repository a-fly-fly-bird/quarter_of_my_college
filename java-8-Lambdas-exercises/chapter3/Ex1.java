package chapter3;

import java.util.List;
import java.util.stream.*;

public class Ex1{
    public static void main(String[] args) {
        System.out.println("Hello World");
    }

    int addUp(Stream<Integer> numbers){
        return numbers.reduce(0, (x,y)->x+y);
    }

    List<String> function2(List<Artist> artists){
        /**
         * Stream.of() Returns a sequential Stream containing a single element.
         * So the below function is wrong.
         */

        return Stream.of(artists)
                    .map(x -> x.getName() + x.getNationality())
                    .collect(Collectors.toList());
        /**
         * The right case
         */
        return artists.stream()
                    .flatMap(artist -> Stream.of(artist.getName(), artist.getNationality()))
                    .collect(Collectors.toList());
        
    }

    List<Album> function3(List<Album> albums){
        return Stream.of(albums)
                    .filter(album -> album.tracks.length <= 3)
                    .collect(Collectors.toList());
    }
}