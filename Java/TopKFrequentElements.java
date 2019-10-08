import java.util.*;

/**
 * Program to find top k frequently present elements in the Input Sample
 *
 * @author neeraj on 07/10/19
 * Copyright (c) 2019, Algorithms-HacktoberFest.
 * All rights reserved.
 */
public class TopKFrequentElements {

    public static void main(String[] args) {
        System.out.println(topKFrequent(new int[]{1, 1, 1, 2, 2, 3}, 2));
        System.out.println(topKFrequent(new int[]{1}, 1));
    }

    public static List<Integer> topKFrequent(int[] nums, int k) {
        Map<Integer, Integer> freq = new HashMap<>();
        for (int i : nums) {
            freq.put(i, freq.getOrDefault(i, 0) + 1);
        }
        List<Integer> keys = new ArrayList<>(freq.keySet());
        Collections.sort(keys, (a, b) -> freq.get(b) - freq.get(a));
        List<Integer> result = new ArrayList<>();
        for (int i = 0; i < k; i++) {
            result.add(keys.get(i));
        }
        return result;
    }
}
