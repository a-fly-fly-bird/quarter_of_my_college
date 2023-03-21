package chapter3;

public class Ex2 {
    public static int countBandMembersInternal(List<Artist> artists) {
        return artists.stream()
                    .flatMap(artist -> artist.getMembers())
                    .count();
        
        /**
         * 另外一种
         */
        return artists.stream()
                    .map(artist -> artist.getMembers().count())
                    .reduce(0, Long::sum);
    }   
}
