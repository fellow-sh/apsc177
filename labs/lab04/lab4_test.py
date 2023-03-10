import numpy as np
import subprocess

for _ in range(10):
    size = np.random.randint(5, 15)
    sample = np.random.randint(-100, 100, size=(size))
    print(np.mean(sample), np.var(sample, ddof=1), np.std(sample, ddof=1), sep='\n')

    samplef = ' '.join(map(str, np.concatenate([[size], sample])))
    subprocess.run(['./Lab4'], input=samplef.encode())
    print('=' * 80)
