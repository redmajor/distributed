from statistics import median, mean, stdev

file = open('/home/rafael/mestrado/distributed/results/mydyn.26914276.comet-33-11.out')
content = file.read()
lines = content.split('\n')
lines = [line for line in lines if len(line) >= 1]

lines = [line.split() for line in lines]


results = {'p': {}, 'c': {}, 'i': {}}
it = iter(lines)

for line in it:
    dist = line[0]
    load = float(line[1])
    alg = '_'.join(line[2:])

    if alg not in results[dist]:
        results[dist][alg] = {}

    if load not in results[dist][alg]:
        results[dist][alg][load] = {'rt': []}

    if dist == 'p':
        for i in range(100):
            next(it)

    response_time = float(next(it)[0])
    next(it)

    results[dist][alg][load]['rt'].append(response_time)


def list_algs(results):
    algs = set()
    for alg in results:
        algs.add(alg)
    return algs


def list_loads(results):
    loads = set()
    for item in results.values():
        for load in item:
            loads.add(load)
    return loads


def gen_rt_table(type, results, operation=mean):
    results = results[type]
    algs = list_algs(results)
    loads = list_loads(results)

    table = 'Load '
    for alg in algs:
        table += alg + ' '
    table += '\n'
    for load in loads:
        table += str(load) + ' '
        for alg in algs:
            try:
                table += str(operation(results[alg][load]['rt'])) + ' '
            except KeyError:
                table += '* '
        table += '\n'
    return table


print(gen_rt_table('c', results, stdev))
print()
print(gen_rt_table('p', results, stdev))