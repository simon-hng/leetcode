#[derive(Debug)]
struct Solution {}
impl Solution {
    pub fn find_median_sorted_arrays(nums1: Vec<i32>, nums2: Vec<i32>) -> f64 {
        let merged: Vec<i32> = Self::merge(nums1, nums2);

        let i = merged.len() / 2;
        if merged.len() % 2 == 0 {
            return ((merged[i] as f64) + (merged[i - 1] as f64)) / 2.0;
        }

        merged[i] as f64
    }

    pub fn merge(nums1: Vec<i32>, nums2: Vec<i32>) -> Vec<i32> {
        let mut iter1 = nums1.iter().peekable();
        let mut iter2 = nums2.iter().peekable();
        let output: Vec<i32> = vec![0; nums1.len() + nums2.len()];
        print!("{}", output.len());

        output
            .iter()
            .map(|_| match (iter1.peek(), iter2.peek()) {
                (None, None) => unreachable!("How"),
                (None, Some(&&val)) => {
                    iter2.next();
                    val
                }
                (Some(&&val), None) => {
                    iter1.next();
                    val
                }
                (Some(&&val1), Some(&&val2)) => {
                    if val1 < val2 {
                        iter1.next();
                        val1
                    } else {
                        iter2.next();
                        val2
                    }
                }
            })
            .collect()
    }
}

fn main() {
    todo!("{:#?}", Solution {})
}

#[cfg(test)]
mod merge_test {
    use crate::Solution;

    #[test]
    fn example_1() {
        assert_eq!(Solution::merge(vec![1, 3], vec![2]), vec![1, 2, 3]);
    }

    #[test]
    fn example_2() {
        assert_eq!(Solution::merge(vec![1, 2], vec![3, 4]), vec![1, 2, 3, 4]);
    }
}

#[cfg(test)]
mod solution_tests {
    use crate::Solution;

    #[test]
    fn example_1() {
        assert_eq!(
            Solution::find_median_sorted_arrays(vec![1, 3], vec![2]),
            2.0
        );
    }

    #[test]
    fn example_2() {
        assert_eq!(
            Solution::find_median_sorted_arrays(vec![1, 2], vec![3, 4]),
            2.5
        );
    }
}
