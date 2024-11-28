import fields2cover as f2c
import Mapping


rand = f2c.Random(42)
field = rand.generateRandField(1e4, 5)
cell = field.getField()
# Mapping.drawCell(cell)
