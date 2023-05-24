use std::{collections::HashMap, vec};

fn dfs(graph: &HashMap<i32, Vec<i32>>, visited: &mut Vec<bool>, node: i32) {
    if visited[node as usize] {
        return;
    }

    visited[node as usize] = true;

    graph[&node].iter().for_each(|x| dfs(graph, visited, *x))
}
fn main() {
    let n: usize = 10;

    let graph = HashMap::from([
        (0, vec![1, 2, 3]),
        (1, vec![0, 4, 5]),
        (2, vec![0, 6, 7]),
        (3, vec![0, 8, 9]),
        (4, vec![1]),
        (5, vec![1]),
        (6, vec![2]),
        (7, vec![2]),
        (8, vec![3]),
        (9, vec![3]),
    ]);

    let mut visited = vec![false; n];

    let start_node = 0;

    dfs(&graph, &mut visited, start_node);

    graph.into_iter().for_each(|x| {
        println!("{} is visited {}", x.0, visited[x.0 as usize]);
    })
}
