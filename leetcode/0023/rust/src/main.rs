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
    type Item = Box<ListNode>;

    fn next(&mut self) -> Option<Self::Item> {
        let (iter_index, next) = self
            .lists
            .iter()
            .enumerate()
            .filter_map(|(index, value_option)| value_option.as_ref().map(|value| (index, value)))
            .reduce(|acc, e| match e.1.val > acc.1.val {
                true => return acc,
                false => return e,
            })?;

        let next = next.to_owned();
        self.lists[iter_index] = self.lists[iter_index].clone().map(|e| e.next)?;
        Some(next)
    }
}

impl ListsIter {
    fn merge(&mut self) -> Option<Box<ListNode>> {
        let mut dummy_head = Box::new(ListNode::new(0));
        let mut tail = &mut dummy_head;

        for next_node in self {
            tail.next = Some(next_node);
            tail = tail.next.as_mut().unwrap();
        }

        dummy_head.next
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

    lists_iter.for_each(|e| println!("{:?}", e))
}
