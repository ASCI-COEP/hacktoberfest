package hacktoberfest

/**
 * Activity Selection implementation in Kotlin
 * Algorithmic Paradigm - Greedy Algorithm
 * Assumes that the activities are already sorted according to their finish time
 * Time Complexity - O(n)
 */

object ActivitySelection {

    /**
     * Prints a maximum set of activities that can be done by a single
     * @param start integer array containing start time of activities
     * @param finish integer array containing finish time of activities
     */
    private fun selectMaxActivities(start: IntArray, finish: IntArray) {
        var i: Int = 0
        var j: Int = 1

        print("The following activities are selected : \n")

        // The first activity is always selected as its end time is minimum
        print("$i ")

        while (j < start.size) {
            // If current activity has start time greater than or equal to the
            // finish time of previously selected activity, it is selected
            if (start[j] >= finish[i]) {
                print("$j ")
                i = j
            }
            j++
        }
    }

    @JvmStatic
    fun main(args: Array<String>) {

        val start = intArrayOf(1, 3, 0, 5, 8, 5)
        val finish = intArrayOf(2, 4, 6, 7, 9, 9)

        selectMaxActivities(start, finish)
    }
}
