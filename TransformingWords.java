import java.util.*;


public class TransformingWords {
    public static void main(String args[]) throws Exception {
        String start, end;
        Set<String> dict = new HashSet<>();
        int N;
        Scanner sc = new Scanner(System.in);
        start = sc.nextLine();
        end = sc.nextLine();
        N = sc.nextInt();
        for (int i = 0; i < N; i++) {
            String temp;
            temp = sc.nextLine();
            dict.add(temp);

        }
        System.out.println(length(start, end, dict));
    }

    public static int length(String begin, String end, Set<String> wordsDict) {
        Queue<String> curLevel = new LinkedList<>();
        Queue<String> nextLevel = new LinkedList<>();
        curLevel.add(begin);

        wordsDict.add(end);

        String curWord;
        int level = 1;

        Set<String> visited = new HashSet<>();

        while (!curLevel.isEmpty()) {
            level++;
            while (!curLevel.isEmpty()) {
                curWord = curLevel.poll();
                visited.add(curWord);


                char[] arr = curWord.toCharArray();
                for (int i = 0; i < arr.length; i++) {
                    for (char c = 'a'; c <= 'z'; c++) {
                        char temp = arr[i];
                        if (arr[i] != c) {
                            arr[i] = c;
                        }

                        String newWord = new String(arr);

                        if (newWord.equals(end)) {
                            return level;
                        }
                        if (wordsDict.contains(newWord) && !visited.contains(newWord)) {
                            nextLevel.add(newWord);
                        }

                        arr[i] = temp;
                    }
                }
            }
            curLevel = nextLevel;
            nextLevel = new LinkedList<>();

        }

        return 0;
    }
}
