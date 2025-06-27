func ChangeBlock(oldTrans, newTrans string, chainHead *Block) {
    current := chainHead
    var previous *Block = nil

    for current != nil {
        for i, t := range current.transactions {
            if t == oldTrans {
                // Update the transaction
                current.transactions[i] = newTrans
                // Recalculate hash
                current.currentHash = CalculateHash(current)

                // Propagate hash changes forward
                next := chainHead
                for next != nil && next.prevPointer != current {
                    next = next.prevPointer
                }
                for next != nil {
                    next.prevHash = current.currentHash
                    next.currentHash = CalculateHash(next)
                    current = next
                    next = nil
                    for tmp := chainHead; tmp != nil; tmp = tmp.prevPointer {
                        if tmp.prevPointer == current {
                            next = tmp
                            break
                        }
                    }
                }

                fmt.Println("Transaction changed and hashes updated.")
                return
            }
        }
        previous = current
        current = current.prevPointer
    }

    fmt.Println("Transaction not found.")
}
