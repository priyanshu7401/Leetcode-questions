# Write your MySQL query statement below


select
        Tree.id,
        IF(Tree.p_id is null,'Root'
          ,IF(Tree.id in (select subtree.p_id from Tree as subtree),'Inner','Leaf'))'Type'
From
    Tree
           
