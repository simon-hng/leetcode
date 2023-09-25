// Definition for singly-linked list.
#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
    pub val: i32,
    pub next: Option<Box<ListNode>>,
}

impl ListNode {
    #[inline]
    fn new(val: i32) -> Self {
        ListNode { next: None, val }
    }
}

struct ListsIter {
    lists: Vec<Option<Box<ListNode>>>,
}

impl Iterator for ListsIter {
    type Item = Option<Box<ListNode>>;

    fn next(&mut self) -> Option<Self::Item> {
        let (iter_index, next) =
            self.lists
                .iter()
                .flatten()
                .enumerate()
                .reduce(|acc, e| match e.1.val > acc.1.val {
                    true => return acc,
                    false => return e,
                })?;
        let next = next.to_owned();

        self.lists[iter_index] = self.lists[iter_index].clone().map(|e| e.next)?;

        Some(Some(next.to_owned()))
    }
}

impl ListsIter {
    fn merge(&mut self) -> Option<Box<ListNode>> {
        let mut dummy_head = Some(Box::new(ListNode::new(0)));
        let mut tail = &mut dummy_head;

        while let Some(next_node) = self.next() {
            tail.unwrap().next = next_node;
            tail = &mut tail.unwrap().next
        }

        dummy_head.unwrap().next
    }
}

struct Solution {}
impl Solution {
    pub fn merge_k_lists(lists: Vec<Option<Box<ListNode>>>) -> Option<Box<ListNode>> {
        ListsIter { lists }.merge()
    }
}

fn main() {
    let mut list1 = Some(Box::new(ListNode::new(1)));
    let mut list1_tail = list1.as_mut().unwrap();
    list1_tail.next = Some(Box::new(ListNode::new(4)));
    list1_tail = list1_tail.next.as_mut().unwrap();
    list1_tail.next = Some(Box::new(ListNode::new(5)));

    let mut list2 = Some(Box::new(ListNode::new(1)));
    let mut list2_tail = list2.as_mut().unwrap();
    list2_tail.next = Some(Box::new(ListNode::new(3)));
    list2_tail = list2_tail.next.as_mut().unwrap();
    list2_tail.next = Some(Box::new(ListNode::new(4)));

    let mut list3 = Some(Box::new(ListNode::new(2)));
    let list3_tail = list3.as_mut().unwrap();
    list3_tail.next = Some(Box::new(ListNode::new(6)));

    let lists_iter = ListsIter {
        lists: vec![list1, list2, list3],
    };

    lists_iter.flatten().for_each(|e| print!("{}", e.val))
}
