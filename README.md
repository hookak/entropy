# Block layer IO tracing with Data

IO tracing + Data (date is generated by some parameter)

Support DAC

## Getting Started

clone this project


### Installing


you will do

```
make
```

then 'generator', 'csvToLba', 'blkToLba' excutable file 


'csvToLba' make csv file to lba input File
Download MSR Cambridge Traces http://iotta.snia.org/tracetypes/3

```
./csvToLba hm_0.csv hm_0_lba.in
```

```
./generator [Output file] [LBA sequence file] [entropy] [page distribution] [page difference] [LBA range] [RW mode]
```

you can use like this
```
./generator output.dac hm_0_lba.in 0.59 1 0.3 0.5 0
```

## Parameter
### Output file format

         request_dir          lpa             request_size                  date 

 |-------------- 8 bytes -------------|-------8 bytes------|-------------- 8 bytes ---------------|----------(request_size* 4096) bytes----------|

### entropy

0 < entorpy < 1

### page distribution
* 1 : UNIFORM distribution
* 2 : NORMAL distribution

### page difference

0 <= page difference <= 1

page difference is possibility of 1K block change

### LBA range

0 <= LBA range

if Input LBA range [100G], and LBA range = 0.5,
   generated LBA range is [100G * 0.5] = [50G]

### RW mode
   * 0 : RW
   * 1 : W


