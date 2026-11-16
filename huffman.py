
import heapq
from collections import Counter

# Node class for Huffman Tree
class Node:
    def __init__(self, char, freq):
        self.char = char
        self.freq = freq
        self.left = None
        self.right = None

    def __lt__(self, other):
        return self.freq < other.freq


# Generate Huffman Codes
def huffman_encoding(text):
    frequency = Counter(text)
  
    # Create a min heap
    heap = [Node(char, freq) for char, freq in frequency.items()]
    heapq.heapify(heap)

    # Build Huffman Tree using Greedy Strategy
    while len(heap) > 1:
        left = heapq.heappop(heap)
        right = heapq.heappop(heap)

        new_node = Node(None, left.freq + right.freq)
        new_node.left = left
        new_node.right = right

        heapq.heappush(heap, new_node)

    # Generate codes
    codes = {}

    def generate_codes(node, code=""):
        if node is None:
            return

        if node.char is not None:
            codes[node.char] = code if code else "0"
            return

        generate_codes(node.left, code + "0")
        generate_codes(node.right, code + "1")

    generate_codes(heap[0])

    # Encode text
    encoded_text = "".join(codes[ch] for ch in text)

    return codes, encoded_text


# Main program
text = input("Enter a string: ")

if text:
    codes, encoded_text = huffman_encoding(text)

    print("\nHuffman Codes:")
    for char, code in sorted(codes.items()):
        print(repr(char), ":", code)

    print("\nEncoded String:", encoded_text)
else:
    print("Please enter a valid string.")
