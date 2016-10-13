import os, sys, re, math
from pylab import *
from helper import *
import matplotlib.ticker as mtick

#matplotlib.use('Agg', True)

lineconfig = {}
linestyles = ['-', '--', ':']

# summer time
#colors = ["#e8d174", "#e39e54", "#d64d4d", "#4d7358", "#9ed670"]

# YCSB color
#colors = ["#007011", "#35cccc", "#fc9900", "#fc53ee", "#5257f2"]
#colors = ["#70a2e4", "#8970e4", "#70e4ab", "#178890", "#077562"]

# TPCC color
colors = ["#ed954a", "#59cb86", "#ffc63e", "#dc6555", "#444444", "#60BD68"]

# 1000 core paper palette
#colors = ['#4D4D4D', '#5DA5DA', '#FAA43A', '#60BD68', '#F17CB0', 
#		  '#B2912F', '#B276B2', '#DECF3F', '#F15854']

markers = ['o', '^', 'x', 'D']
#lineconfig['DL_DETECT'] = "ls='%s', lw=4, color='%s', marker='%s', ms=8" % (':', colors[0], 'x')
#lineconfig['NO_WAIT'] = "ls='%s', lw=3, color='%s', marker='%s', ms=6" % (linestyles[0], colors[3], markers[1])
#lineconfig['TICTOC'] = "ls='%s', lw=3, color='%s', marker='%s', ms=6" % ('-', colors[8], 'o')
#lineconfig['SILO'] = "ls='%s', lw=3, color='%s', marker='%s', ms=6" % ('--', colors[2], markers[3])

lineconfig['DL_DETECT'] = "ls='%s', lw=4, color='%s', marker='%s', ms=8, markeredgewidth=2" % (':', colors[4], 'x')
lineconfig['NO_WAIT'] = "ls='%s', lw=3, color='%s', marker='%s', ms=6" % ('-', colors[3], '^')
lineconfig['TICTOC'] = "ls='%s', lw=3, color='%s', marker='%s', ms=6" % ('-', colors[2], 'o')
lineconfig['SILO'] = "ls='%s', lw=3, color='%s', marker='%s', ms=6" % ('--', colors[0], 'D')
lineconfig['TS_ALLOC'] = "ls='%s', lw=3, color='%s', marker='%s', ms=8, markeredgewidth=2" % ('--', colors[1], '+')
lineconfig['HEKATON'] = "ls='%s', lw=3, color='%s', marker='%s', ms=8, markeredgewidth=2" % ('--', colors[1], '+')
#lineconfig['DTA'] = "ls='%s', lw=3, color='%s', marker='%s', ms=8, markeredgewidth=2" % ('--', colors[1], '+')


lineconfig['DTA'] = "ls='%s', lw=3, color='%s', marker='%s', ms=6" % ('--', colors[3], 'D')
lineconfig['TICTOC_RR'] = "ls='%s', lw=3, color='%s', marker='%s', ms=6" % ('-', colors[4], '^')

ccs = ['SILO', 'No Opts', 'NoWait', 'NoWait + PreAbort', 'All Opts']
lineconfig['No Opts'] = "ls='%s', lw=3, color='%s', marker='%s', ms=6" % ('-', colors[3], '^')
lineconfig['NoWait'] = "ls='%s', lw=3, color='%s', marker='%s', ms=8, markeredgewidth=2" % ('--', colors[4], '+')
lineconfig['NoWait + PreAbort'] = "ls='%s', lw=3, color='%s', marker='%s', ms=6" % ('-', colors[2], 'o')
lineconfig['All Opts'] = "ls='%s', lw=3, color='%s', marker='%s', ms=8, markeredgewidth=2" % (':', colors[5], 'x')

# data[linename][x index] 
def draw_line(fname, data, xlabels, 
		bbox=(0.9,0.9), ncol=1, 
		ylab='Throughput', logscale=False, 
		ylimit=0, xlimit=None, xlab='Thread Count',
		legend=True, linenames = None, figsize=(5, 2.5), vline=None, 
		top=None, bottom=0.18, left=0.2, right=0.95) :
	fig = figure(figsize=figsize)
	thr = [0] * len(xlabels)
	lines = [0] * len(data)
	n = 0
	if linenames == None :
		linenames = sorted(data.keys())
	for key in linenames:
		intlab = [float(x) for x in xlabels]
		style = ''
		if key in lineconfig.keys():
			style = lineconfig[key]
		pattern = re.compile(".*rperc0.*_theta0.*")
		if key == 'DL_DETECT':
			if (pattern.match(fname) or 'wh4' in fname or 'wh1' in fname):
				intlab = [1, 4, 10, 20, 40]
				m_data = data[key][0:5]
			elif 'whsweep' in fname:
				intlab = [40, 80]
				m_data = data[key][-2:]
				print m_data
			else: 
				m_data = data[key]
			exec "lines[n], = plot(intlab, m_data, %s)" % style
		else :
			exec "lines[n], = plot(intlab, data[key], %s)" % style
		n += 1
	if ylimit != 0:
		ylim(ylimit)
	if xlimit != None:
		xlim(xlimit)
	plt.locator_params(nbins=6)
	plt.gca().set_ylim(bottom=0)
	ylabel(ylab)
	xlabel(xlab)
	ticklabel_format(axis='y', style='sci', scilimits=(-3,5), size=20)
	if legend :
		legend_names = linenames #[x.replace('_', '\_') for x in linenames]
		fig.legend(lines, legend_names, loc='right', prop={'size':11}, ncol=ncol, bbox_to_anchor=bbox)
		# fig.legend(lines, linenames, bbox_to_anchor = bbox, prop={'size':11}, ncol=ncol)
	subplots_adjust(left=left, bottom=bottom, right=right, top=top)
	ax = plt.axes()
	ax.yaxis.set_major_formatter(mtick.FormatStrFormatter('%.1f'))
	axes = ax.get_axes()
	axes.yaxis.grid(True,
					linestyle='-',
					which='major',
					color='0.75'
	)
	ax.set_axisbelow(True)
	if vline != None:		
		fill_between([40,80], 0, ax.get_ylim()[1], facecolor='gray', alpha=0.3, edgecolor="none")

	savefig('figs/' + fname +'.pdf')#, bbox_inches='tight')
	close(fig)

def draw_bar(filename, data, label, names=None, dots=None, 
		ylabel='Norm. Thrput.', xlabel='', rotation=0, logscale=False,
		enable_xticks = True,
		y2label='Norm. Traffic',
		ncol=4, bbox=[0.95, 1.05], colors=None, hatches=None,
		figsize=(9, 2), left=0.07, bottom=0.18, right=0.99, top=0.78, 
		ylimit=None, xlimit=None, margin=0.2, fig=None, ax=None,
		y2limit=None, vline=True,
		hline=None, legend=True, shuffle_legend=False):

	index = range(0, len(label))
	m_label = list(label)
	if fig == None and ax == None :
		fig, ax1 = plt.subplots(figsize=figsize)
	else : 
		ax1 = ax
	ax1.set_ylabel(ylabel, fontsize=20)
	if logscale:
		ax1.set_yscale('log') #, nonposy='clip')
#	ax1.set_xlabel(xlabel, fontsize=16)
	if hline != None:
		ax1.axhline(hline, color=(0.5,0.2,0.2), lw=2)
	ax1.yaxis.grid(True)
	ax1.tick_params(labelsize=20)
	if dots != None:
		ax2 = ax1.twinx()
		ax2.set_ylabel(y2label, fontsize=20)
		ax2.tick_params(labelsize=20)
	if not logscale:
		plt.locator_params(nbins=8)
#	grid(axis='y')
	width = 1.0 / len(data) / 1.5
	if colors == None :
		colors = [0] * len(data)
		for i in range(0, len(data)) :
			colors[i] = [0.1 + 0.7 / len(data) * i] * 3
	n = 0
	bars = [0] * len(data)
	if names == None: names = data.keys()
	if xlimit == None:
		xlimit = (-0.2,len(index) - 0.3333 + margin)
	ax1.set_xlim(xlimit)
	if ylimit != None:
		ax1.set_ylim(ylimit)
	if y2limit != None:
		ax2.set_ylim(y2limit)
	for cfg in names:
		ind = [x + width*n for x in index]
		hatch = None if hatches == None else hatches[n]
		bars[n] = ax1.bar(ind, data[cfg], width, color=colors[n], hatch=hatch)
		if dots != None:
			ax2.plot([x + width/2 for x in ind], dots[cfg], 'ro', ms=10)
		n += 1
	ax1.set_xticks([x + width*len(names)/2.0 for x in index])
	if enable_xticks:
		ax1.set_xticklabels(m_label, size=20, rotation=rotation)
	else : 
		ax1.set_xticklabels([''] * len(m_label), size=20)
	#ax1.set_xticklabels(index, m_label, size='16', rotation=rotation)
	plt.tick_params(
		axis='x',		  # changes apply to the x-axis
		which='both',	  # both major and minor ticks are affected
		bottom='off',	  # ticks along the bottom edge are off
		top='off',		 # ticks along the top edge are off
		labelbottom='on') # labels along the bottom edge are off
	if legend :
		if shuffle_legend :
			nrow = len(names) / ncol
			shuffle_bars = [0] * len(bars)
			shuffle_names = [0] * len(names)
			for n in range(0, len(bars)):
				shuffle_bars[n/ncol + n%ncol*nrow] = bars[n]
				shuffle_names[n/ncol + n%ncol*nrow] = names[n]
			bars = shuffle_bars
			names = shuffle_names
		fig.legend([x[0] for x in bars], names, prop={'size':20}, 
			ncol=ncol, bbox_to_anchor=bbox, labelspacing=0.2) 
	subplots_adjust(left=left, bottom=bottom, right=right, top=top)
	#plt.annotate("sssssssssss", xy = (1, 0.5), xytext = (1, 0.5))
	if vline != None:		
		fill_between([40,80], 0, ax1.get_ylim()[1], facecolor='gray', alpha=0.3, edgecolor="none")

	savefig('figs/' + filename + '.pdf') #, bbox_inches='tight')
	return bars

"""
# data[barname][stackname] = [values the stack] * number_of_groups 
def draw_stack(data, result, figname='stack_graph', xlabels=None, figsize=(8, 3)) :
	fig = figure(figsize=figsize)
	time_man = [0] * len(data)
	time_wait = [0] * len(data)
	time_index = [0] * len(data)
	time_ts = [0] * len(data)
	time_abort = [0] * len(data)
	time_all = [0] * len(data)
	ind = range(0, len(data))
	if xlabels == None:
		keys = data.keys()
	else :
		keys = xlabels
	n = 0
	for i in range(0, len(data)) :
		max_thr = 0
		for suffix in ['', '_1', '_2', '_3', '_4'] :
			fname = data[ keys[i] ]
			if fname in result[suffix] and \
				(result[suffix][fname]['txn_cnt'] / result[suffix][fname]['run_time'] > max_thr):
				max_thr = result[suffix][fname]['txn_cnt'] / result[suffix][fname]['run_time']
				time_man[n] = (float(result[suffix][fname]['time_man']) +\
					 	  	  float(result[suffix][fname]['time_index'])) / result[suffix][fname]['txn_cnt']
				time_abort[n] = float(result[suffix][fname]['time_abort']) / result[suffix][fname]['txn_cnt']
				time_all[n] = float(result[suffix][fname]['run_time']) / result[suffix][fname]['txn_cnt']
		n += 1
	norm = time_all[0]
	ylabel("Norm. Runtime")
	for i in range(0, n):
		time_man[i] /= norm 
		time_abort[i] /= norm 
		time_all[i] /= norm 
	xticks([x+0.4 for x in ind], keys, rotation=18, ha='center', size=11)
	p1 = plt.bar(ind, time_man, color='#e8d174')
	bottom = time_man
	p2 = plt.bar(ind, time_abort, color='#e39e54', hatch='\\\\', bottom=bottom)
	bottom = [a + b for a,b in zip(bottom, time_abort)]
	time_work = [a - b for a,b in zip(time_all, bottom)]
	p3 = plt.bar(ind, time_work, color='#9ed670', hatch='/', bottom=bottom)
	legend((p3, p2, p1),\
		('Useful Work', 'Abort', 'Manager'),\
		 bbox_to_anchor = [1, 1.35], prop={'size':11}, ncol=3)
	subplots_adjust(bottom=0.22, left=0.13, right=0.95, top=0.8)
	savefig('figs/' + figname + '.pdf') #, bbox_inches='tight')
"""

# data[barname][stackname] = [values the stack] * number_of_groups 
def draw_stack(data, groupnames, stacknames, barnames, 
            figname='stack_graph', figsize=(20,4),
            ylab='Norm. Network Traffic',
            bottom=0.2, left=0.1, right=0.98, top=None, 
            ncol=1, bbox=[0.67,1.1], bg=False) :
   colors = [
      "color='#409D48', hatch='//'",
      "color='#5DA5DA'",
      "color='#F8E86F', hatch='/'",
      "color='#FAA43A', hatch='\\\\'",
      "color='#F15854'",      
   ]
   fig = figure(figsize=figsize)
   ngroup = len(groupnames)
   nbar = len(barnames)
   nstack = len(stacknames)
   ind = range(0, ngroup)
   stacks = [0] * nstack
   width = 1.0 / 1.618 / nbar
   
   xlim([-0.382, ngroup])   
   xticks([x + 0.618/2 for x in ind], groupnames, rotation=30, size=20)
   ylabel(ylab, fontsize='20')
   yticks(fontsize='20')

   axes = plt.axes().get_axes()
   axes.yaxis.grid(True, linestyle='--', which='major')
   axes.set_axisbelow(True)
   if bg:
      plt.axvspan(21.8, 23, facecolor='g', alpha=0.2)

   #axes.axhline(1.0, color=(0.5,0.2,0.2), lw=2)

   for bid in range(0, nbar):
      barname = barnames[bid]
      bot = [0] * ngroup
      for sid in range(0, nstack) :
         stackname = stacknames[sid]
         if stackname in data[barname] :
            exec "stacks[sid] = plt.bar(ind, data[barname][stackname],\
               width=%f,bottom=bot, %s)" % (width, colors[sid])
            bot = [a + b for a,b in zip(bot, data[barname][stackname])]
      ind = [x + width for x in ind]
   legend([x[0] for x in stacks], stacknames, bbox_to_anchor = bbox, prop={'size':20}, ncol=ncol)
   subplots_adjust(left=left, bottom=bottom, right=right, top=top)
   savefig('figs/' + figname + '.pdf')
   return axes   


def draw_legend(fname='legend', linenames = ['DL_DETECT', 'HEKATON', 'NO_WAIT', 'SILO', 'TICTOC'], figsize=[11.1, 0.5], bbox=[1.01, 1.18], ncol=5):
	fig = figure(figsize=figsize)
	lines = [0] * len(linenames)
	for n in range(0, len(linenames)):
		key = linenames[n]
		style = lineconfig[key]
		exec "lines[n], = plot([0], [0], %s)" % style
	ax = plt.axes()
	axes = ax.get_axes()
 	axes.get_yaxis().set_ticks([])
 	axes.get_xaxis().set_ticks([])
	#legend_names = [x.replace('TICTOC', 'TICTOC') for x in linenames]
	legend_names = linenames #[x.replace('_', '\_') for x in linenames]
	leg = fig.legend(lines, legend_names, prop={'size':18}, ncol=ncol, bbox_to_anchor=bbox)
	leg.get_frame().set_linewidth(2)
	savefig('figs/' + fname +'.pdf')#, bbox_inches='tight')
	close(fig)
