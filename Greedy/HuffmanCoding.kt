package hacktoberfest

import java.util.PriorityQueue
import java.util.Comparator

class Node {

    var data: Int = 0
    var char: Char = ' '

    var left: Node? = null
    var right: Node? = null
}

internal class MyComparator : Comparator<Node> {
    override fun compare(x: Node, y: Node): Int {

        return x.data - y.data
    }
}

object Huffman {

    private fun printCode(root: Node, s: String) {

        if (root.left == null
                && root.right == null
                && Character.isLetter(root.char)) {

            println(root.char + ":" + s)
            return
        }

        printCode(root.left!!, s + "0")
        printCode(root.right!!, s + "1")
    }

    @JvmStatic
    fun main(args: Array<String>) {

        val n = 6
        val arr = charArrayOf('a', 'b', 'c', 'd', 'e', 'f')
        val frequency = intArrayOf(5, 9, 12, 13, 16, 45)

        val q = PriorityQueue(n, MyComparator())

        for (i in 0 until n) {
            val node = Node()

            node.char = arr[i]
            node.data = frequency[i]

            node.left = null
            node.right = null

            q.add(node)
        }

        var root: Node? = null

        while (q.size > 1) {
            val x = q.peek()
            q.poll()
            val y = q.peek()
            q.poll()
            val f = Node()
            f.data = x.data + y.data
            f.char = '-'
            f.left = x
            f.right = y
            root = f
            q.add(f)
        }

        printCode(root!!, "")
    }
}
