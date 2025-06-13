/*

.................................1--
.................................|--
...............+--------------------------------+--
...............|--..............................|--
...............2--..............................3--
...............|--..............................|--
.....+-----------------+--...............+-----------------+--
.....|--...............|--...............|--...............|--
.....4--...............nil...............nil...............7--
.....|--...............|--...............|--...............|--
+---------+--.....+---------+--.....+---------+--.....+---------+--
|--.......|--.....|--.......|--.....|--.......|--.....|--.......|--
8--.......9--.....nil.......nil.....nil.......nil.....14-.......15-



...............1--
...............|--
.....+-----------------+--
.....|--...............|--
.....2--...............3--
.....|--...............|--
+---------+--.....+---------+--
|--.......|--.....|--.......|--
4--.......5--.....6--.......7--


......1--
......|--
+---------+--
|--.......|--
2--.......3--

*/

/*

// Pseudocode of Function to visualize a binary tree in a console using ASCII art
visualize_binary_tree(root, w=3) {
    if [ root is nil ] then
        print 'nil\n'
        return
    fi

    mrsp = w+2 // minimum root prefix spacing
    mcsp = (2 x mrsp) - w // minimum child prefix spacing
    h = height(root) // height of binary tree
    n = 2 ^ (h-1) // max possible nodes at last level of binary tree
    g = floor(n/2) // max possible group of pairs at last level of binary tree

    prsp = max(mrsp, floor(((g x mcsp) + ((g-1) x mrsp) + (n x w))/2)) // prefix root spacing
    pcsp = max(mrsp, floor(prsp/(2 x mrsp)) x mrsp) // prefix child spacing
    icsp = max(mcsp, floor(prsp/2) x mrsp) // inter child spacing
    icgsp = prsp // inter childs group spacing


    queue q = empty
    current_level = 1
    nodes_count = 0
    did_print_branch = false

    q.push(root)
    while [ q is not empty ] do
        current_node = q.front()
        q.pop()
        
        nodes_count += 1

        if [ did_print_branch is true ] then
            for [ i = 0 to prsp ] do
                print ' '
            fi
            
            loops_count = 0
            n = floor((2 ^ (current_level - 1)/2)
            
            // connecting child branches to parent
            for [ i = 1 to n (inclusive) ] do
                if [ i is even ] then
                    for [ j = 0 to icsp ] do
                        print ' ' icsp times
                    fi
                else if [ i > 1 ] then
                    for [ j = 0 to icgsp ] do
                        print ' ' icgsp times
                    fi
                end if
                
                // vertical branch
                print '|' left-aligned within a field of width w
            fi

            print '\n'
            if [ pcsp != mrsp ] then
                for [ i = 0 to pcsp ] do
                    print ' '
                fi
            end if

            if [ current_level > 1 and nodes_count is 1 ] then
                icsp = max(mcsp, floor(prsp/mrsp) x mrsp)
            fi

            // connecting child nodes branches in a pair
            for [ i = 1 to n (inclusive) ] do
                if [ i > 1] then
                    for [ j = 0 to icgsp ] do
                        print ' '
                    fi
                end if

                print '+' left-aligned within a field of width w
                
                for [ j = 0 to icsp ] do
                    print '-'
                fi

                print '+' left-aligned within a field of width w
            fi

            print '\n'
            if [ pcsp != mrsp ] then
                for [ i = 0 to pcsp ] do
                    print ' '
                fi
            end if

            // connecting child nodes group branch with child nodes
            for [ i = 1 to n (inclusive) ] do
                if [ i > 1] then
                    for [ j = 0 to icgsp ] do
                        print ' '
                    fi
                end if

                print '|' left-aligned within a field of width w

                for [ j = 0 to icsp ] do
                    print ' '
                fi

                print '|' left-aligned within a field of width w
            fi

            print '\n'

            if [ pcsp != mrsp ] then
                for [ i = 0 to pcsp ] do
                    print ' '
                fi
            end if

            did_print_branch = false
        end if

        if [ current_level is 1 ] then
            for [ i = 0 to prsp ] do
                print ' '
            fi
        end if

        // print current node data
        if [ current_node is null ] then
            print 'nil' left-aligned within a field of width w
            q.push(null)
            q.push(null)
        else
            print current_node.data left-aligned within a field of width w
            q.push(current_node.left)
            q.push(current_node.right)
        end if

        max_possible_nodes = 2 ^ (current_level - 1)
        if [ nodes_count == max(1, max_possible_nodes) ] then
            print '\n'
            current_level += 1
            nodes_count = 0
            did_print_branch = true;
            
            if [ current_level > h ] then
                break
            else if [ current_level > 1 ] then
                prsp = pcsp
                pcsp = max(mrsp, floor(prsp/(2 x mrsp)) x mrsp)
                icgsp = prsp
            end if
        else 
            if [ nodes_count is even ] then
                for [ i = 0 to icgsp ] do
                    print ' '
                fi
            else
                for [ i = 0 to icsp ] do
                    print ' '
                fi
            end if
        end if
    done
}


*/




