# 人类活动对径流模拟影响小结

因为要基于数据驱动讨论这方面的问题，所以需要简单总结已有的文献，其中涉及的数据相关的内容，可以参考research－data项目。

本文先按时间顺序总述各个文章的主要内容。

## Calibrating a watershed simulation model involving human interference

这篇文章是[Calibrating a watershed simulation model involving human interference: an application of multi-objective genetic algorithms](https://doi.org/10.2166/hydro.2008.010)，其应用的方法是一种比较常见的在小范围内做人类活动影响的径流预报修正中使用的方法。这类方法处理问题的出发点是流域径流预报模型如何将水库运行的规律包含其中，然后通过率定的方式量化确定这种影响。

所以他面临的问题就可以归纳为：怎么在模型预报和率定中考虑的水库运行的规律。

在人类活动的影响方面，有一种分类方式如下：

- 对水文系统的特征的改变，包括land use，land cover；
- 对水文系统的动态冲击影响，比如水库下泄，取水，灌溉，回流等。

这篇文章主要考虑第二种影响，其主要思路是：

1. 用水库水位－流量关系定义水库运行；
2. 然后将由上述关系定义的水库泄流加入一个误差校正项中来率定模型。


具体方法上，作者用了一个分布式水文模型进行水文模拟计算，及综合考虑Minimizing the root-mean-square-error，Minimizing the deviation in runoff depth，Minimizing the deviation in peak flow magnitude和Minimizing the deviation in time to peak的多目标MOGA算法率定模型，然后在模型中，认为调度操作会引起径流模拟的一个误差项$\epsilon (t)$：
$$R(t)=R^*(t)+\epsilon (t)$$
具体地说，该误差项反映了：

- instant changes in streamflow and subsequently an abrupt change of the shape of the observed streamflow hydrograph triggered by human interference
- a systematic error with the storage–release function
- the aggregated effect of both

由于这是一个确定的误差项，所以才可以要通过率定的方式去分析。

结果上这里主要看看对比有没有上述误差项的区别。

根据原文图5，在率定中应用的多目标算法的收敛方面，考虑误差项的帕累托前沿收敛的更快，在所有目标上都是这样。

从原文图6可以看出随着误差项范围的增加，所有三个目标都能有所改进，从无到有这一步变化比较明显，到10%－20%之间时就没有明显区别了。

还有其他的一些说明，暂时略。

总之，该文是将水库下泄作为一个系统误差来考虑，已获得更准确的率定模型，从结果上看是有必要的。

## How can man-made water reservoirs be accounted for in a lumped rainfall-runoff model

这篇文章将水库影响以artificial storages的形式考虑进了集总式模型中，其出发点是水库对下游的影响随着径流的扩散，变得不像在刚出口处那样影响直接，且河道特性的描述也比较困难，因此考虑起来比较困难；如何考虑这种**对下游站点径流的影响**是这片文章讨论的重点，这种影响在反映流域上整体建设的水库对一个流域出口站点径流的作用是有益的。

水库的建设会影响流域的蒸发，下渗和输移，这些明显是会影响大坝下游流域的behavior的。有大量的研究将能控制这些影响的参数纳入研究范围，有dam location, operating regulations, reservoir capacity in comparison with runoff, climatic and hydrological conditions。

直接研究这些影响的方式是利用分布式模型，将水库纳入到模型的子单元中，通过显式地参数化这些变量到单元中，可以显式地考虑这些变量的影响。但这种方法有一定局限性，因为分布式模型所需的数据较多，很多时候没办法面面俱到，因此分布式模型的性能并没有体现出比集总式模型强大之处。但是将这种影响放入集总式模型中有一些难点：

- 在集总式模型中，dam的位置在流域上是较难考虑的；
- 另外，集总式模型多是达尔文式模型，比较难直接反映流域的物理信息，因此水库的影响很难定位到集总式模型中。

那么要如何考虑呢，首先看看水库对下游站点的影响可以由什么因素衡量？

- 从静态属性方面，The associated reservoirs also represent an interesting variety of characteristics in terms of：**volume, location within the watershed (close to or far from the outlet) and management objectives (flood control, low flow augmentation, irrigation, hydropower, water supply, etc.)**.

- 从动态影响看，Data collected to characterize the behavior of reservoirs are **daily time series of stored volumes (volumes are generally more widely available than detailed records of all the reservoir inflow and outflow series). 这些数据反映了水库管理的类型。 水库库容可以用水位库容曲线+水位的方式获取。水库径流输入也是重要因素，不过本文假设站点处没有径流测站。

然后在方法上，作者是这么考虑的：

1. 把流域上所有水库集总到流域尺度上，即一个水库的库容变化都等价为整个流域上；
2. 在水文模型中，将流域水库作为一个存储单元考虑，平均到流域整体；
3. 根据观测，将流域平均的动态库容水位变化(每个时段一个$\triangle V$)表达出来，不带参数，这就是真实反映实际调度的。

那么$\triangle V$加入到模型的哪个部分：The transfer function? The production function?
Both?

这块就采用了模拟的方式来进行判断了，分几种不同的情形进行模拟分析，得到：

- If the stored volume variation $\triangle V$ is negative (i.e., the stored volume in reservoirs decreases), $\triangle V$ is added to the content of the routing store (见原文 Figure 3);
- If $\triangle V$ is positive (i.e., the stored volume increases), $\triangle V$ is subtracted from the content of the production store (见原文Figure 3).

最后的结果（原文图4）表明，the method developed can effectively account for reservoirs despite the lumped modeling approach, with significant improvements in the simulation of low flows, but more limited for high flows.

## Qualifying human disturbance in watersheds

这篇是USGS制作GAGES数据集时采用的分析人类活动影响的方法，并不针对径流模拟，不过在disturbance的分析方面，还是有不少值得分析的地方。尤其它是基于GIS提取的变量对人类活动的干扰进行量化，所以其**提取的指标是十分重要的参考**。文献全名[Quantifying human disturbance in watersheds: variable selection and performance of a GIS-based disturbance index for predicting the biological condition of perennial streams](https://www.sciencedirect.com/science/article/abs/pii/S1470160X09000983)，主要是计算了一个名为human disturbance index的指标，具体方法如下所示。

首先，目的是量化流域内人类活动影响的程度。那么如何量化呢？首先要对人类活动的影响进行变量描述，然后再依据这些变量进行计算。

因此问题就归结为选择什么变量描述，以及如何整合这些变量进行计算。

首先，根据GIS数据选择了33个方便获取的变量。这些变量包括：




然后以USEPA分类的受影响严重(DIS)、中等（MED）、不严重（REF）的流域为率定和验证的标准。来分析哪些变量及组合和计算方法能最有效地区分受影响程度严重与不严重。

那么如何确定变量及组合的方式？

因为直接试验所有33个变量的所有组合方式计算量太大，因此要选择一些进行计算，论文选择了四个组合方式。

第一种是直接选择33个变量；

第二种叫做Reduced-Original数据集。首先计算33个变量两两之间的Spearman's rho，以此确定相关性较高的变量，选出rho>0.7的变量组合；
然后将每个变量作为可观测值排序，将disturbance、Reference当做类别变量，进行Kruskal-Wallis卡方检验，卡方越大，说明概率越小，越能拒绝disturbance和reference相同的零假设，所以卡方越大越好。
因此在相关性高的变量中选择卡方较大的值。再通过减掉卡方小的变量等操作，可以得到最后一组变量；

第三种是Reduced-Synthetic数据集。该组变量是通过PCA主成分分析算法获取的。首先基于专业知识将33个变量分成5个类别。对每一个类别利用PCA算法将其中所有变量降维到新变量上，即Principle Components(PCs)。这里选取了各个类别的第一个主成分，即每个选择了一个主维度，这样就得到了5个新变量；

第四种称作Redundant dataset。和第二种类似，不过包含了一些相关的变量做冗余，为了检验冗余的效果。即把和第二种相关的变量包含进来，得到22个变量。

有了四组变量组合后，可以确定计算方法，即如何对影响程度进行量化。

对变量代表的影响程度进行打分是常用的方法，具体而言就是基于流域人数的相对值来分配影响点数，该方法有几种变种：

第一种，range-standardize。首先变量被scale到0-10生成一组原始的disturbance值，然后利用权重，加权平均计算得到一个index。

第二种，the Percentile>0方法。对各项变量数据排序，从0开始，等距打分，然后加权平均。

第三种，the Percentile>50方法。和上述方法类似，只不过是从50开始。

至于具体的加权方法，也有三种：

第一种是权重一样；

第二种是卡方作为权重；

第三种是PC权重。

利用上述方式，最后得到的最能区分的变量组合和计算方法是：Reduced-Original数据集+Percentile>0打分+卡方权重。

最后用这一套方法计算得到的就是hydrologic disturbance index。

## Influence of Reservoir Operation in the Upper Reaches of the Yangtze River (China) on the Inflow and Outflow Regime of the TGR-based on the Improved SWAT Model

这篇文章主要讲了长江上游流域(URYR)基于SWAT模型的模拟如何考虑人类活动影响，这是比较经典的一种方式，就是直接在分布式模型中模拟水库的运行，进而分析其影响。

关于人类活动影响水文循环，文章认为主要是四个方面：

- water taking
- water transporting
- water usage
- drainage and regress

用SWAT模型讨论人类活动影响主要是在如下方面讨论：Reservoir control module is improved by adding reservoir level limit, and discharge from the reservoir is controlled。

因为是分布式模型，所以用到的数据也较多，包括: 

1. The **DEM** of URYR, which is SRTM 90 m digital elevation data (download from http://srtm.csi.cgiar.org/) with the scale of 1:250000; 
2. **Daily weather information** in the 105 rainfall stations, such as **precipitation, temperature, wind speed, solar radiation and relative humidity** from China national meteorological stasions; 
3. **River flow data** from seven hydrological stations obtained from the water resources department of Yangtze hydrographic office; 
4. Parameters of **16 land use type and the land use map** (scale of 1:100,000) obtained from CAS (Chinese Academy of Sciences); 
5. **Soil types, attributes and the soil map** with the scale of 1:1000,000, provided by the water resources department of Yangtze hydrographic office; 
6. Data of **51 large-scale reservoirs and 139 mid-scale reservoirs** from the water resources department of Yangtze hydrographic office; 
7. **Reservoir parameters (level of dead water, Flood limit water level, dead storage, combined capacity of storing, et al.)** from the monograph of electric power planning of China.

具体在SWAT模型中水库是作为单独的模块模拟运行的，三峡梯级水库按照三峡梯级调度规则模拟，URYR其他水库按照调度图模拟运行。

## Integrated hydrological modelling of small- and medium-sized water storages with application to the upper Fengman Reservoir Basin of China

这是张老师的一篇文章。这篇基本思路是尽可能利用可以使用的数据信息来对流域中小水利工程的蓄泄能力进行建模，主要是利用Landsat的数据，和针对不同大小的截流河调节能力水利设施的一个经验库容分类方法和一组水库库容下泄经验关系，来改进SWAT2005模型模拟能力。

案例分析就是放在了中国东北丰满流域，该流域有很多为了灌溉，工业用水和生活用水而建的中小蓄水工程。将改进的SWAT2005与原始的模型对比分析。

具体方法上说，因为有成百上千的小水库，因此是不可能在一个模型中对每个小水库一一建模的，而是采用一种聚合的方式，在大尺度流域范围内合理的模拟中小水库群的蓄泄行为。且不同级别的水库的处理方式是不同的，大型水库有详细的设计和调度信息，但是小型水库只有行政级别的地理位置，流域面积，库容等基本信息。对于塘坝，那就只有流域级别的流域面积和库容量了。因此要对库容进行分组。

选择SWAT模型是因为它本身就包括这一块的模拟，可以在流域尺度评估storage的影响。对于大中型水库的模拟，采用的还是原SWAT模型，这部分和前一篇文章区别不大，不够再表面积和体积关系方面，采用了分级分别估计的方式，在对小水库的处理上采用了聚合水库的方式。

Landsat主要是用来处理水体表面积的。有了表面积之后可以进行面积库容关系的分级建立。

**不同水库的slopes, storages, and drainage areas不同，这影响面积库容关系**。因此将slope, storage, and drainage area三个因素作为分级构建面积库容关系时的重要考量。分级是依据drainage areas与storage volume的比例。具体步骤可见原文。

然后在分析河道水量平衡方面，采用了大小水库分开运算的方法，小水库采用聚合的方法计算。小水库位置已知，可认为是并联的。具体计算方式可见原文。

然后关于water－use数据，做了简化处理，文章认为用水的空间分布是和land use及天气情况相关。分了两个时期，分别对pond，reaches和shallow aquafers定义了参数来表示。

这篇文章细节很足，和SWAT模型结合也比较紧密，有需要再回来看。

其应用的数据有：

- DEM data
- Soil data
- Land use data
- Digital river network data
- Daily precipitation data
- Individual water storage characteristics
- Water use data

原文图7展示了计算对比结果，可以看到S1的结果是优于S0的。

## Large dams and alluvial rivers in the Anthropocene

这也是一篇来自USGS的文章，记录这篇的原因是可以了解关于dam对河道影响的分析。

讨论the effects of dams and reservoirs的很多,但是their impacts have been studied individually，而这篇文章主要讨论的是their interaction along a river corridor。这篇文章将主要问题放在了两个dam之间的Upper Missouri River的morphological and sedimentological changes。该文说明the influence of the upstream dam is still a major control of river dynamics when the backwater effects of the downstream reservoir begin. 因为大坝很多都是以梯级的形式串联出现在河道上，因此这篇文章提出了这样的概念：dams之间的联系如何影响河流geomorphology，导致distinct and recognizable **morphologic sequences** that we term **‘Inter-Dam sequence’ characteristic** of major rivers in the US.

Dam对河道的r morphology and fluvial processes都会有很大影响，包括Flow regimes, channel morphology, sediment transport, and ecological processes等. 

对河道下游影响的研究有很多文献，channel改变的基本原因是sediment supply和stream flow之间的不平衡，导致坝后sediment缺少或过多，这种改变可能会在数百公里范围的下游都有。具体的表现有bed degradation and narrowing, changes in channel bed texture or armoring, bed aggradation, bar construction, channel widening等。

对河道上游影响的研究也不少，尤其是水库的sedimentation，这种sediment和reservoir geometry and sediment concentration有关。水库沉积和地貌过程变化会形成不同区域，比如headwater deltas, deep water fine-grained deposits, and turbidity currents。

这篇文章就是对上下游混合影响的分析，这里暂略了，如果后面有数据需求，再回头看。

## River flow changes related to land and water management practices across the conterminous United States

这篇文章分析全美的land and water management practices (LWMP)对river flow影响的文章，也是USGS的研究人员写的，因此是比较重要的一篇。他是对全美4196个被影响的河流评估flow alteration－－几个自然条件下的flow metrics的deviation。

摘要中先点出了几个重要的改变径流的原因：比较重要的是road density和dams，然后是agricultural development和wastewater discharges也在一些流域有关系。这几个因素里，dam通常是减少flow的大部分attributes的，而road density，agriculture 和 wastewater discharge是更倾向于增加径流的。

这篇文章出发点是Understanding how LWMP—singly and in combination—change stream and river flows is key to maintaining and restoring natural flow regimes. 

关于gap的分析是这样的：
以往的研究都是针对有 pre- and post-LWMP changes记录的河流，或者有 both upriver and downriver flow records的河流的，但是能够有这种隔离的测站是不多的，所以大多研究都是针对的少数流域；
另外，城市化对径流影响的研究结论并不一致；
而关于dam的影响，基本是认为会减少high flow，增加月径流，尤其在枯水期。也有研究表明减少了丰水期月径流。大部分研究都认为dam是最重要的影响因素；
除了urbanization和dam，agriculture也被认为是一个重要的影响因素，不过由于各自研究对象不同，因此结论也各有情况。

所以这篇文章就在全美CONUS范围内分析径流变化的人类活动影响。

为了避免前面提到的隔离能力测站的缺失，扩充研究数据，需要的数据就仅仅是：perennial flow, a minimum period of record, and characterization of the gauged river drainage watershed in terms of the natural and human factors that commonly affect flow metrics. 即有持续径流记录，要求最低的记录时间范围，和影响有测量的流域的径流度量值的自然和人类活动影响因素的特征。

使用的方法是quantifies flow deviations from natural conditions in watersheds that can experience any number of LWMP

最后的目标是：

1. 识别影响flow change的一些比较common的LWMP；
2. 看看空间上这些影响是怎么分布的；
3. 提升对于LWMP如何影响径流的理解。

（这些目标也是我想要认识的）

关于数据方面，使用了全美4196个站点，这些站点代表了广泛的气候和LWMP范围。站点的选择主要是依据1990－2009间至少有10年数据的，且径流记录是常年不断的。最后他用来分析flow changes和LWMP之间关系的空间区域是GAGES里定义的ecoregions，这些ecoregions是有相似的topography, climate, and natural vegetation的，会以相似的形式对LWMP响应的区域。

这里定义了5个flow metrics来代表flow regime的几个重要方面，包括：

- the average of the annual 1-day maximum flow (hereafter annual maximum),年均日最大径流 
- average of the annual 7-day minimum flow (low flow), 年均7天最小径流
- average May, July, and November flows 5／7／11月平均径流

选择这些指标是比较**主观的**(这大概也是big data的机会吧)，主要是基于以前的文献使用的方法。径流数据的获取和统计都有USGS-R程序可供使用。

关于LWMP，选择了13个指标作为径流变化的预测因子，也是从GAGES那篇文章里找出来的13个LWMP相关的指标。可以参考原文table1。也要结合Qualifying human disturbance in watersheds一文重点理解。主要包括的范围是 

- watershed land use and land-use change, 
- irrigation,
- the impacts of dams (reservoir storage and dam density) as quantified in the National Inventory of Dams (NID), 
- road density,  
- wastewater discharge locations identified in the National Pollutant Discharge Elimination System (NPDES) by the United States Environmental Protection Agency (http://cfpub.epa.gov/npdes/). 
- a simple reservoir storage index (STI, total reservoir storage volume divided by estimated annual runoff, in volume/year) was calculated to express the NID-based reservoir capacity in terms of years of available water storage（NID数据库仅仅代表最大的70000个水库，不并不包括上百万的小水体）

起初四个变量被认为能代表general effects of infrastructure associated with land development:

- road density (RDS), 
- population density, 
- percent impervious surfaces,
- percent urban land cover in the watershed. 

但是它们之间的相关性很高，所以冗余，因此最后只选择了第一个RDS来代表，RDS也是最常用的一个代表land development的指标。

数据准备完毕之后，方法部分是采用random forest regression来评估flow changes和LWMP之间的关系，对每个ecoregion，每个flow metric构建RF模型，因此就有45个RF回归模型。步骤地关键是：

1. 量化每条河每个flow metric同自然条件下的flow metric的deviation；
2. 分析这种deviation和LWMP之间的关系；
3. 识别统计上显著的LWMP。

第一条中自然条件下的期望值怎么计算？这篇文章是通过一种统计计算的方式来估计的，统计模型是通过1035个相对不受人类活动影响的河流测站分析得到的，该模型利用climate和topography等指标来预测自然径流值。交叉验证误差在观测值10%以内就认为该模型是较好的模型。对于low flow可以放宽到15%，因为low－flow不好预测。

后面就是RF的应用了，对于任何一对相关关系绝对值超过0.5的LWMP变量，都只选择其中一个即可，RF的结果用变量方差来判断好坏。

LWMP变量的相对重要性则由the increase in node purity values 决定。该值由the mean decrease in the mean squared error of the RF model that results when each LWMP variable was, in turn, randomly permuted.纯度是决策树中的一个术语，表示的是分类正确或回归准确的能力，纯度越高代表预测越好。总之，随机森林算法中可以轻松实现特征重要性的排序，也因此是一种常用的分析特征重要性的算法。然后再用Partial Dependence Plot绘出每个ecoregion中flow changes和最重要的LWMP predictors的关系。

结果主要展示在table2和fig2，3中。这里主要记录下关键变量，其余的可参考原文。在大多数的ecoregion和flowmetrics中，RDS都是最关键的predictor。Dams主要和annual maximum值相关，在大多数ecoregion也是最重要的指标之一，根据图3可以看出storage增大，各个flow metrics是减小的。其余的flow metrics都是和指标正相关的。农业在个别region中是最重要的指标。

## Impact of human activities on stream flow in the Biliu River basin, China 

这篇也是zhang老师的文章，主要就是看看数据，了解一些可能的影响因素。

首先这篇文章主要是通过模拟不同人类活动和气候场景下的径流来分析不同场景是如何影响径流的，结果表明artificial water consumption 和the precipitation (wet, normal and dry) of the year相关，也是f the decrease in runoff during each period and for each different wetness year的重要原因。另外land use变化增加了一点径流，水库的影响减少径流。

其中，水库的指标主要是大小类型，建成年份，库容和库容率。
land use变化主要是土地利用类型的面积和比例的变化。
artificial water consumption是通过SWAT模型模拟计算出来的。

## Catchment coevolution

这篇文章Catchment coevolution: A useful framework for improving predictions of hydrological change?主要是对landscape feature的空间模式和流域水文响应之间的关系作综述，这个关系被称作Catchment coevolution。其研究的尺度比较宏观，这里我只关心最长几十年范围内的landscape变化对水文径流的影响，因此重点关注这方面的一些driver是什么。

作者综述了经验性的catchment coevolution，确认三类大的drivers是：

- climate
- geology
- tectonics

然后确定了可以比较这些独立驱动的活动水平的通用方法，这样，至少在概念上，可以量化evolution或aging的速度，这里有一个说法就是age，是把流域赋予了年龄，然后其有一个演化的过程，然后这个分析是针对流域水文响应的，因此分析这个年龄是和水文分析相结合的，所以是coevolution概念下的age。两种方法：

1. 基于将当前的landscape特征与径流过程相关联，假定径流过程负责当前landscape中的footprint
2. 利用了一种被称为“空时替代”的实验设计。

分析这的意图是如果想预测hydrologic change，需要预测catchment是怎么随drivers coevolve的。

首先地质尺度那非常大，在几十年的尺度上是没有明显变化的，这里就略了；

然后是climate time scale，这里说的尺度也是千年尺度的，也很大；

接着就是ecosystem time scale，这个尺度就和人类活动相关了，主要是突然的自然变化和人类活动。这部分会驱动流域的aging。具体的没太展开，所以就暂略了。

## Integrating a reservoir regulation scheme into a spatially distributed  hydrological mode

这篇文章主要是讨论了如何将水库调度包含到一个分布式水文模型中，是一种经典范式的新使用，主要看看输入的数据即可。

模型的输入有：

- 水文参数
    - elevation : DEM from SRTM, . Flow directions, basin mask, soil depth, and stream network were generated from the DEM
    - soil: from the STATSGO2 database
    - vegetation characteristics: land cover data from NLCD
- 水库参数
    - Impoundment Date
    - downstream control points
    - Sedimentation rate
    - storage, from the USACE, storage capacity was divided into the surcharge pool, the flood control pool, the conservation pool, and the inactive pool , power generation rate, average annual power production
    - elevation
    - surface area
- 气象参数
    - precipitation,
    - maximum temperature,
    - minimum temperature,
    - wind speedrelative humidity,
    - incoming shortwave radiation,
    - incoming longwave radiation

## Satellite Remote Sensing for Water Resources Management

这篇文章Satellite Remote Sensing for Water Resources Management: Potential for Supporting Sustainable Development in Data-Poor Regions介绍了很多现在正在WRM中用的，可以用的以及将来可能会用到的遥感数据，并阐述了益处和面临的问题。

首先，是**Data needs for WRM**。

主要参考原文table1。个人觉得比较不错，因此copy一遍。

|水资源管理决策|用于决策的水相关数据|传统数据源|
|-|-|-|
|**规划设计**|-|-|
|防洪|降雨径流长期记录，cold regions长期SWE|雨量站、径流站网，snow courses and pillows|
|水电系统|径流长期记录，cold regions长期SWE|同上|
|灌溉系统|降雨、径流和地下水长期记录，crop用水估计|雨量站、径流站网，wells、piezometers，气象网|
|污水处理系统|径流、地下水等的feed sources的记录|径流站网，wells、piezometers|
|供水系统|降雨径流和地下水记录|雨量站、径流站网；wells、piezometers|
|跨境水|长期径流和地下水记录，用水记录|径流站网，wells、piezometers|
|**管理运行**|-|-|
|水资源管理（满足需水）|实时降水、蒸发、径流和地下水|雨量站网，eddy-covariance towers, 径流站网， wells、piezometers|
|供水调度（保证可靠性）|实时降水、蒸发和地下水|同上|
|水电调度|实时降水、蒸发、径流、降水预报|雨量站，径流站，气象站，天气预报|
|防洪调度|实时降水、径流和SWE、降水预报|雨量站，径流站，snow courses and pillows，天气预报|
|污水管理|实时径流和地下水数据|径流站，wells、piezometers|
|灌溉系统调度|实时降水、径流、地下水和土壤含水量，蒸发估计|雨量站、径流站网，wells、piezometers，土壤含水量probes，eddy-covariance towers，气象站|
|生态系统管理|近期降水、径流、水位、土壤含水量和水质数据|雨量站、径流站、水位站、水质采样|
|**灾害管理**|-|-|
|crop监测和粮食安全|实时vegetation特征、crop需水、土壤含水量、降水预报|田间crop采样，eddy-covariance towers，气象站，土壤含水量probes，天气预报|
|干旱早期预警和管理|实时降水、土壤含水量、径流、地下水、降水预报|雨量站，土壤含水量probes，径流站，wells、piezometers，天气预报|
|洪水早期预警和管理|实时降水，径流和降水预报|雨量站、径流站、天气预报|
|水健康|实时降水、地表水和水质参数|雨量站、径流站、水位站、水质采样|

table2总结了**WRM需要的变量以及数据源**，也copy一遍。

|变量|数据源|空间覆盖|时间覆盖|Utility for WRM|
|-|-|-|-|-|
|**降水**|测站网|国家测站网|年到几十年；实时受限|必要，但是实时和空间覆盖上可用性受限|
||遥感|极地外全球|10-15年亚日尺度数据，近实时|在站点稀疏地区必要，但受限于较大不确定性和短时间范围|
||模型|区域到全球|可变，近实时|全球和几十年的范围但较大不确定性|
|**ET,PET**|测站网（pan PET）|国家测网|年到几十年|对评价crop需水有必要|
||Flux towers（ET）|有限测点|1-10年|数量有限，空间代表性有限，主要用于验证|
||遥感（ET,PET）|区域到全球|几十年，近实时|全球和几十年的范围但较大不确定性|
||模型（ET,PET）|区域到全球|几十年，近实时|全球和几十年的范围但较大不确定性，需要前提知识|
|**径流**|测站网|国家测站网|几十年，近实时|必要，但很多地区不可用|
||遥感|仅大河|年到几十年，实时性有限|较大不确定性，范围有限，但可用处还是必要的|
||模型|区域到全球|几十年，近实时|在无观测地区只能用它，有很大不确定性，代表性差|
|**水位**|测站网|特定水体|年到十年，实时性有限|必要但是许多地区没有|
||遥感|受限于大河和水体|年到十年，实时|范围有限，但对特定水体有用|
||模型||几十年，近实时|较大不确定性但在许多地方是唯一数据源|
|**土壤含水量**|测站网|有限空间覆盖|年，实时性有限|对局部应用有用，用作验证很有必要|
||遥感|全球|年到几十年，近实时|有限深度，但是如果和模型结合很有用|
||模型|全球|几十年，近实时|较大不确定性，但是对干旱应用有用|
|**雪和冰**|测站网|区域的|年到几十年，一些站点近实时|测站较密是有必要||
||遥感|全球|年到几十年，近实时|必要，但是SWE有较大不确定性，对snow covered地区更准确|
||模型|全球|几十年，近实时|较大不确定性，但是可以和in-situ及遥感互补|
|**地下水**|well测网|区域性||必要，但覆盖有限，可用于验证|
||遥感|来源于全球重力测量，但空间分辨率低|年，低分辨率|测量的是TWSA，地下水需要进一步建模，粗分辨率使得不能直接使用，但是结合模型可用于研究|
||模型|区域到全球|年到几十年，有时近实时|较大不确定性，但是对与区域应用有用|
|**水质**|采样点|有限的空间覆盖|年，实时上受限|必要但是覆盖率差|
||遥感|全球|年，近实时|仅仅表面水变量，有的变量不确定性大|
||模型|取决于变量|年到几十年，近实时|有的变量不确定性较大|

接着，记录下具体的目前可用的遥感技术和产品。都在table3，这里也copy下，最后引用就不copy了，看原文。

|名称|发射和服役时间|空间分辨率|时间分辨率|
|-|-|-|-|
|**Precipitation**||||
|TMPA|2000-2018|0.25° 60°S to 60°N|3h|
|PERSIANN|2000-|0.25° 60°S to 60°N|1h
|CMORPH|2002-|0.07° 60°S to 60°N|30min|
|GSMAP|2005-|0.1°  global|1h|
|GPM/IMERG|2015-|0.1° 60°S to 60°N|30min|
|CHIRPS|1979-|0.05°|daily|
|MSWEP|1979-|0.1°|3h|
|**Land Surface Temperature(for ET)**|-|-|-|
|Landsat|2013(Landsat-8),2022(Landsat-9)|30(multisoectral)-100m(thermal)|16d|
|AVHRR|NOAA_19 2009发射，MetOp-B 2012发射|1km|1d|
|ASTER|2000|90m|16d|
|MODIS|2000|1km/6km|1d,8d|
|VIIRS|2011|375-750m|1d|
|Sentinel-3|2015/2017|1km|<2d|
|ECOSTRESS|2018,1y expected|38×69m|平均4天，focus区域亚日尺度|
|**ET Products**||||
|RS-PM|1983-2010|0.5°|daily|
|MOD16 ET|2000-2014|1km|8d|
|PT-JPL|1984-2006|1-0°|Monthly|
|GLEAM|1980-2016,2003-2015,2011-2015|0.25°|Daily|
|SSEBop|2003-|1km|10d|
|ALEXI-DisALEXI|Various regional data sets|30m(Landsat),1km(MODIS)|Hourly/daily|
|Global ESI|2001-|0.05°|4- and 12-week composites updated weekly|
|**Soil moisture**||||
|AMSR-E|2002-2011|25km|1d revisit|
|AMSR2|2012|25km|1d revisit|
|SMOS|2010|15,25,50km|1- to 3-day revisit; daily, 9-d and monthly|
|SMAP , SMAP L4 root zone soil moisture|36km,9km|1-3d revisit, 3h|
|Sentinel-1|2014/2016|<1km$^2$|8d|
|**Surface water height and extent**||||
|Jason-2/3(surface water height)|2008/2016|Lakes>100km$^2$|10d|
|Sentinel-3(surface water height)|2016|350m along track|27d|
|Landsat(surface water height)|2013(Landsat-8),2022(Landsat-9)|30(multisoectral)-100m(thermal)|16d|
|MODIS(surface water height)|2000-|500m|Daily|
|Sentinel-2(surface water height)|2015/2017|10-60m|5/10d|
|**Snow**||||
|MODIS SCE|2000-|500m, 0.05°|daily and 8d composite|
|VIIRS SCE|2012-|375m(swath),500m|daily and 8d composite|
|AMSR-E SWE|2000-2011|25km|daily, 5d, monthly|
|**Groundwater**||||
|GRACE|2002|500000km$^2$|30d|
|GRACE FO|2017|500000km$^2$|30d|
|**Vegetation**||||
|Landsat|2013(Landsat-8),2022(Landsat-9)|15m|16d|
|AVHRR/GIMMS|1979-2015|1km|7/14d composites|
|MODIS|2000|250m, 1km, 0.05°|16d,mongthly|
|VIIRS|2012|375m(swath),500m|daily and 8d composite|
|SPOT/PROBA-V|1990-2017|1km|10d|
|Sentinel-2|2015/2017|10-60m|5/10d|

剩下的先不管了，直接先试下GAGES-II里面流域的水库密度和水库库容等属性，把代码跑一下。

## Quanfying

这篇luweiwei学姐的文章，看看中小水库对径流影响的分析都注重了哪些因素。

## Quantifying

这篇文章也是可以看看都用了哪些数据的，并且方法上可能也有可借鉴之处。

## Analysis 

这篇也是流域属性的影响

## Reservoir

这篇是分析对洪峰的影响，可以好好看看。

## Unsupervised

这篇是一个非监督分类，其数据的运用也是比较详细的，可借鉴。

## hydropower dams

比较综述的一篇，可以看看

## Low stream

也是USGS的一篇文章，可认真看看。

## climate

也是一个流域属性影响的文章。

## Real-time reservoir operation using recurrent neural networks and inflow forecast from a distributed hydrological model

这是一篇新文章，yangdawen老师组的用RNN来进行水库影响的径流模拟的计算。
