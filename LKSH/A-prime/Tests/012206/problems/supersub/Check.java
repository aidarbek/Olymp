import static ru.ifmo.testlib.Outcome.quit;

import java.math.BigInteger;

import ru.ifmo.testlib.Checker;
import ru.ifmo.testlib.InStream;
import ru.ifmo.testlib.Outcome;
import ru.ifmo.testlib.Outcome.Type;
import java.util.*;

public class Check implements Checker {

    final static String NO = "NO";
    final static int ALPHABET = 10;

    static int count(String s, char c) {
        int ret = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == c) {
                ret++;
            }
        }
        return ret;
    }

	@Override
	public Outcome test(InStream inf, InStream ouf, InStream ans) {
        String str = inf.nextToken();
        int n = inf.nextInt();
        SuffixAutomaton sa = new SuffixAutomaton(str.length(), ALPHABET).build(str);
        for (int i = 0; i < n; i++) {
            String s = inf.nextToken();
            String s1 = ouf.nextToken();
            String s2 = ans.nextToken();
            if (s1.equals(NO) && s2.equals(NO)) {
                continue;
            }
            if (!s1.equals(NO)) {
              for (int j = 0; j < s1.length(); j++) {
                char ch = s1.charAt(j);
                if (!(ch == '|' || (ch >= 'a' && ch <= 'j')))
                  quit(Type.PE, "Unexpected char: " + ch);
              }
            }
            if (s1.equals(NO)) {
                quit(Type.WA, "Contestant didn't find the answer, but it exists");
            }
            if (s1.contains("||")) {
                quit(Type.WA, "One of the outputed elements is empty string");
            }
            String[] t = s1.split("\\|");
            StringBuilder sb = new StringBuilder();
            for (String e : t) {
                if (!sa.contains(e)) {
                    quit(Type.WA, "\"" + e + "\" is not a substring of \"" + t + "\"");
                }
                sb.append(e);
            }
            String answer = sb.toString();
            if (!answer.equals(s)) {
                quit(Type.WA, "Answer of contestant is \"" + s1 + "\", concatenation of its elements is not \"" + s + "\"");
            }
            int c1 = count(s1, '|') + 1;
            int c2 = count(s2, '|') + 1;
            if (c1 > c2) {
                quit(Type.WA, "Number of elements in contestant's answer is " + c1 + ", but there is the solution that has " + c2 + " elements");
            }
            if (c1 < c2) {
                quit(Type.FAIL, "Number of elements found by contestant is " + c1 + ", but jury has " + c2);
            }
            if (s2.equals(NO)) {
                quit(Type.FAIL, "Contestant found right answer, but jury didn't expect any answer");
            }
        }
        quit(Type.OK, "OK");
        return null;
	}


    static class SuffixAutomaton {
		int[][] link;
		int[] sufLink;
		int[] length;
		int free;
		int root;
		int last;

		public SuffixAutomaton(int maxLength, int alphabet) {
			maxLength = maxLength * 2 + 1;
			link = new int[alphabet][maxLength];
			for (int[] d : link) {
				Arrays.fill(d, -1);
			}
			sufLink = new int[maxLength];
			length = new int[maxLength];
			free = 1;
			root = last = 0;
			sufLink[0] = -1;
		}

        SuffixAutomaton build(String s) {
            for (int i = 0; i < s.length(); i++) {
                int c = s.charAt(i) - 'a';
                append(c);
            }
            return this;
        }

		void append(int c) {
			int newNode = free++;
			length[newNode] = length[last] + 1;
			while (last != -1 && link[c][last] == -1) {
				link[c][last] = newNode;
				last = sufLink[last];
			}
			if (last == -1) {
				sufLink[newNode] = root;
				last = newNode;
				return;
			}
			int q = link[c][last];
			if (length[q] == length[last] + 1) {
				sufLink[newNode] = q;
				last = newNode;
				return;
			}
			int copy = free++;
			length[copy] = length[last] + 1;
			for (int i = 0; i < link.length; i++) {
				link[i][copy] = link[i][q];
			}
			while (last != -1 && link[c][last] == q) {
				link[c][last] = copy;
				last = sufLink[last];
			}
			sufLink[copy] = sufLink[q];
			sufLink[newNode] = sufLink[q] = copy;
			last = newNode;
		}

        boolean contains(String s) {
            int p = 0;
            for (int i = 0; i < s.length(); i++) {
                int c = s.charAt(i) - 'a';
                if (link[c][p] == -1) {
                    return false;
                }
                p = link[c][p];
            }
            return true;
        }
	}

}
