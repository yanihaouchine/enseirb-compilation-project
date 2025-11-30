#!/bin/bash
for f in Examples/*.myc; do
    echo "Compilation de $f ..."
    ./runComp "${f%.myc}"
done
echo "✅ Compilation terminée."
