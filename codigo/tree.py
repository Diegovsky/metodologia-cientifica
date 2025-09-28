from dataclasses import dataclass
from typing import Self
from sys import stderr


@dataclass
class Node:
    value: int
    left: Self | None = None
    right: Self | None = None

    def insert(self, val: Self):
        if val.value < self.value:
            if self.left is None:
                self.left = val
            else:
                self.left.insert(val)
        else:
            if self.right is None:
                self.right = val
            else:
                self.right.insert(val)

    @classmethod
    def from_list(cls, vals: list[int]) -> Self:
        root: None | Self = None
        while len(vals) > 0:
            val = vals.pop()
            node = cls(val)
            if root is None:
                root = node
            else:
                root.insert(node)
        assert root is not None
        return root

    def to_list(self) -> list[int]:
        a = []

        if self.left:
            a.append(self.left.to_list())
        a.append(self.value)
        if self.right:
            a.append(self.right.to_list())
        return a

    def _to_graphviz(self) -> str:
        a = []
        if self.left:
            a.append(self.left._to_graphviz())
            a.append(f"{self.value} -> {self.left.value}")
        if self.right:
            a.append(self.right._to_graphviz())
            a.append(f"{self.value} -> {self.right.value}")
        return "\n".join(a)

    def to_graphviz(self) -> str:
        return f"digraph {{ {self._to_graphviz()} }}"


sos = [10, 33, 20, 31, -10, 9, 999, 32, 99, 30]
sus = sos

tree = Node.from_list(sus)
# print(tree.to_list())
print(tree.to_graphviz())
