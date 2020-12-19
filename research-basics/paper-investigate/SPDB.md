# Streamflow Prediction in Dammed Basins (SPDB)

按刊出时间顺序，简单记录一些 SPDB 相关的文献要点。

## An Operation-Based Scheme for a Multiyear and Multipurpose Reservoir to Enhance Macroscale Hydrologic Models （2006）

这是这个领域很重要的一篇文章（Hanasaki 2006）。

核心是对水库调度的规则性概化。三步：

首先定义一个下泄系数，
$$k_{rls}=\frac{S_0}{\alpha C}$$
它可以表达每个调度年之间的变化性。基本的逻辑是这样的，一年的总供水量很大程度上取决于初库容以及长期目标需水，长期目标水量用库容乘以一个系数表达，所以可以得到上式。

那么早期的关于第y年总release的初步假设值可以设为：
$$R_y \approx k_{rls} * \bar {i_m}$$

然后给出一个临时的月下泄值：
$$ r_m' = \bar {i_m}+d_m - \bar {d_m} \ \ \ \ \ \  \ \ \ \ \ \   \ \ \ \ \ \    if DPI<1-M$$
$$r_m' = \bar {i_m}(M+(1-M)d_m / \bar {d_m}) \ \ \ \ \ \  otherwise$$

其中，DPI是年均需水和年均径流的比值，M是最小月下泄和年均径流的比值。

这里的基本逻辑是对于需水相对不多的情况，即第一个公式，使用均值分配的方式初步分摊到各个月体现月内差异。对于第二个公式，对应的是需水相对较大的情况，应该使用一种类似hedging 的方式，可以看到$d_m$的系数，计算下为$(1-M)\frac{\bar {i_m}}{\bar {d_m}}$，是小于1的，也就是分配到的需水并不都满足。

最后目标月下泄可以由下式计算：
$$r_m=Rk_{rls}r_m'+(1-R)i_m$$
这一部分主要是再考虑库容 来最后定义月下泄。库容够大，即R=1，那么可以直接将初估的下泄乘以下泄系数即可，就如开始初设的年总下泄那样。当R<1时，可以计算下，即$r_m=Rk_{rls}[(1-M)\frac{\bar {i_m}}{\bar {d_m}}d_m+M\bar{i_m}]+(1-R)i_m$，可以看出还是一个关于demand的线性函数，系数还是小于等于1的，所以这里可以看到对应一种二点hedging。

这三步公式的形式应该是作者根据数据反推出来的，总之，现在已经成为了很多研究的引用基础。

## Calibrating a watershed simulation model involving human interference (2007)

这篇文章是[Calibrating a watershed simulation model involving human interference: an application of multi-objective genetic algorithms](https://doi.org/10.2166/hydro.2008.010)，其应用的方法是一种比较常见的在小范围内做人类活动影响的径流预报修正中使用的方法。这类方法处理问题的出发点是流域径流预报模型如何将水库运行的规律包含其中，然后通过率定的方式量化确定这种影响。

所以他面临的问题就可以归纳为：怎么在模型**预报和率定中考虑的水库运行**的规律。

在人类活动的影响方面，有一种分类方式如下：

- 对水文系统的特征的改变，包括land use，land cover；
- 对水文系统的动态冲击影响，比如水库下泄，取水，灌溉，回流等。

这篇文章主要考虑第二种影响，其主要思路是：

1. 用水库水位－流量关系定义水库运行；
2. 然后将由上述关系定义的水库泄流加入一个误差校正项中来率定模型。

具体方法上，作者用了一个分布式水文模型进行水文模拟计算，这个模型有水库汇流模块，水库用storage–release function based on the physical characteristics of the reservoir and dam 来模拟，可以显式地考虑水库的影响；模型率定方面，Minimizing the root-mean-square-error，Minimizing the deviation in runoff depth，Minimizing the deviation in peak flow magnitude和Minimizing the deviation in time to peak多目标，具体方法是MOGA算法；然后在模型中，认为为了应对需求，比如干旱缺水，防洪预泄等，调度操作会引起径流模拟的一个**误差项**$\epsilon (t)$，：
$$R(t)=R^*(t)+\epsilon (t)$$
具体地说，该误差项反映了：

- instant changes in streamflow and subsequently an abrupt change of the shape of the observed streamflow hydrograph triggered by human interference
- a systematic error with the storage–release function
- the aggregated effect of both

这不是一个随机误差项，是综合反映了多种误差的系统误差项，通过率定的方式去计算每个时段输出的误差项来表示这个系统误差。

结果上这里主要看看对比有没有上述误差项的区别。误差项原文指定了一个观测径流的比例上限，分别是0，5，10，20. 根据原文表3可以看到，有20%范围的误差项能更好修正模型预测。

总之，该文是将水库下泄作为一个系统误差来考虑，已获得更准确的率定模型，从结果上看是有必要的。

## How can man-made water reservoirs be accounted for in a lumped rainfall-runoff model (2008)

这篇文章**将水库考虑进了集总式模型中**。

以往直接研究这些影响的方式都是利用分布式模型，将水库纳入到模型的子单元中，通过显式地参数化这些变量到单元中，可以显式地考虑这些变量的影响。但这种方法有一定局限性，因为分布式模型所需的数据较多，很多时候没办法面面俱到，因此分布式模型的性能并没有体现出比集总式模型强大之处。但是将这种影响放入集总式模型中有一些难点：

- 在集总式模型中，dam的位置在流域上是较难考虑的；
- 另外，集总式模型多是达尔文式模型，比较难直接反映流域的物理信息，因此水库的影响很难定位到集总式模型中。

那么要如何考虑呢，首先看看水库对下游站点的影响可以由什么因素衡量？

- 从静态属性方面，The associated reservoirs also represent an interesting variety of characteristics in terms of：**volume, location within the watershed (close to or far from the outlet) and management objectives (flood control, low flow augmentation, irrigation, hydropower, water supply, etc.)**.

- 从动态影响看，Data collected to characterize the behavior of reservoirs are **daily time series of stored volumes (volumes are generally more widely available than detailed records of all the reservoir inflow and outflow series). 这些数据反映了水库管理的类型。 水库库容可以用水位库容曲线+水位的方式获取。水库径流输入也是重要因素，不过本文假设站点处没有径流测站。

然后在方法上，作者是这么考虑的：

1. 把流域上所有水库集总到流域尺度上，即一个水库的库容变化都等价为整个流域上；
2. 在水文模型中，将流域水库作为一个存储单元考虑，平均到流域整体；
3. 根据观测，将流域平均的动态库容水位变化(每个时段一个$\triangle V$)表达出来，不带参数，这就是真实反映实际调度的。

那么$\triangle V$加入到模型的哪个部分：The transfer function? The production function? Both?

这块就采用了“trial and error”的方式来进行判断，最后敲定了：

- If the stored volume variation $\triangle V$ is negative (i.e., the stored volume in reservoirs decreases), $\triangle V$ is added to the content of the routing store (见原文 Figure 3);
- If $\triangle V$ is positive (i.e., the stored volume increases), $\triangle V$ is subtracted from the content of the production store (见原文Figure 3).

这个方法不用改变参数，只是在模型计算过程中，**从模型的状态量中抽走/加入一部分水量**，这部分水量由聚合水库的库容变化值来确定。

结果（原文图4）表明，the method developed can effectively account for reservoirs despite the lumped modeling approach, with significant improvements in the simulation of low flows（NSlq主要关注low flow，原文图4右）, but more limited for high flows （NSq是主要关注high flow的，即左图）.

## Determining watershed response in data poor environments with remotely sensed small reservoirs as runoff gauges (2009)

这篇文章通过遥感**ASAR观测估计小水库的库容变化**，然后用到水文模型中率定参数，这样把水库的影响也考虑了，还把水库当做观测点了。

卫星的时间分辨率决定了能直接观测和推测的水库库容变化时间尺度，大概是14天。所以中间值要用一些插值方法来处理，原文对水库面积增大和减小时的wet days和dry days有不同的处理方式，详见原文式2和4.

![](Picture2.png)

水库库容变化包括自身落雨和蒸发差值 以及 流域交互的 两部分，因此用公式计算出自身的，剩下的是和水文模型交互的。

研究地区是非洲加纳，数据有限，分布式模型不合适，因此采用参数少的模型，原文以水量平衡公式为核心，分析了当地的水文特征，选择了一些理论来完善平衡公式中的各项，比如Thornthwaite-Mather 过程等，这里暂不详述了。

从原文图7看，quick flow的预测和观测还比较切合；从图8来看，对水库库容变化的预测是挺好的，R2验证期到0.92。

这方法对有SPDB+PUB问题有较好启发。

## Reconstructing 20th century global hydrography: a contribution to the Global Terrestrial Network- Hydrology (GTN-H) (2010)

这篇文章（Wisser 2010）是一个宏观的reconstruct hydrography的论文，在重建的过程中，需要考虑到人类活动影响，比如irrigation，比如reservoirs。

单从reservoirs的角度而言，作者采用了一组简单的函数规则（如下两式）来构建水库release与 actual inflow（$I_t$）和long-term mean inflow ($I_m$) 之间的关系，其中公式的系数都是用的从全球30个水库里归纳的经验性常数。原文用的是分布式模型，所以水库也是放到模型的routing model模块。

![](QQ截图20201219173319.png)

$$S_t=S_{t-1}+(I_t-R_t)\triangle t$$

## Quantifying human disturbance in watersheds: Variable selection and performance of a GIS-based disturbance index for predicting the biological condition of perennial streams (2010)

这篇是USGS制作GAGES数据集时采用的分析人类活动影响的方法，并不针对径流模拟，不过个人论文分析计算的时候用的是GAGES数据集，所以这里有必要补充了解下。GAGES数据集制作中是如何分析disturbance的。它是怎么基于GIS提取的变量对人类活动的干扰进行量化的，**提取的指标**human disturbance index 是什么，具体内容如下。

文章目的是量化流域内人类活动影响的程度。那么如何量化呢？首先要对人类活动的影响进行变量描述，然后再依据这些变量进行计算。

因此问题就归结为选择什么变量描述，以及如何整合这些变量进行计算。

首先，根据GIS数据选择了33个方便获取的变量。这些变量包括：

- Census 2000
- Census 2000 TIGER roads
- National Land Cover Data
- USGS agricultural pesticide data
- USGS nutrient data
- National Resources Inventory：主要是农业的一些土地利用
- USGS NHDPlus 100k streams：主要是一些人工渠的数据
- EPA National Pollutant Discharge Elimination System (NPDES) data：径流站点的密度等
- National Inventory of Dams
- USGS National Altas：矿物相关

然后以USEPA分类的受影响严重(DIS)、中等（MED）、不严重（REF）的流域为率定和验证的标准。来分析哪些变量及组合和计算方法能最有效地区分受影响程度严重与不严重。

那么如何确定变量及组合的方式？

因为直接试验所有33个变量的所有组合方式计算量太大，因此要选择一些进行计算，论文选择了四个组合方式。

第一种是直接选择33个变量；

第二种叫做Reduced-Original数据集。首先计算33个变量两两之间的Spearman's rho，以此确定相关性较高的变量，选出rho>0.7的变量组合；
然后将每个变量作为可观测值排序，将disturbance、Reference当做类别变量，进行Kruskal-Wallis卡方检验，卡方越大，说明概率越小，越能拒绝disturbance和reference相同的零假设，所以卡方越大越好。
因此在相关性高的变量中选择卡方较大的值。再通过减掉卡方小的变量等操作，可以得到最后一组变量；

第三种是Reduced-Synthetic数据集。该组变量是通过PCA主成分分析算法获取的。首先基于专业知识将33个变量分成5个类别，population/roads；land cover；pesticides/nutrients;flow impoundments/diversions；point-source pollution。对每一个类别利用PCA算法将其中所有变量降维到新变量上，即Principle Components(PCs)。这里选取了各个类别的第一个主成分，即每个选择了一个主维度，这样就得到了5个新变量；

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

验证的数据来自USEPA（美国environmental protection agency）的分类REF（reference）还是DIS（non-reference）结果。

然后根据卡方值找到最适合分别disturbed还是non-disturbed 流域的方法，卡方越大，说明越能划分。Reduced-Original(6) 的变量选择和Percentile>0的scoring方法最好。

## High-resolution mapping of the world's reservoirs and dams for sustainable river-flow management （2011）

这篇文章是GRanD大坝数据集的文章。

我关心的除了数据，还提供了一个比较重要的指标 DOR，也就是degree of flow regulation. 就是累积上游库容和径流的比例，基本上就是我们常说的库容系数，也称作water aging，或者change in residence time。有了GRanD和HydroSHEDS，这篇文章得到了比较精确的DOR数据。越高的DOR表示径流可以被储存及在较晚的时候被释放。DOR 大于100%，表明这个径流就完全是人工模式了。DOR大于2%就可以被认为是受影响的了。

总之，分析水库的影响有几个较重要的因素：河流大小，DOR，还有水库的调度模式等。

## An Operation-Based Scheme for a Multiyear and Multipurpose Reservoir to Enhance Macroscale Hydrologic Models （2012）

SWAT模型中加入水库模块，出流的确定也是以给定天的多年平均值为基准的一个$\triangle O(i)$，这个值包括发电，供水和储水三个方面的竞争。三方面都依据当前水位和几个特征水位（汛限水位、发电临界水位、死水位等）之间的差别，结合各月release的多年平均，配合四个参数来计算的。

最后的模拟结果表明，相比于SWAT内置的水库模块以及多元回归（Vi与 Vi-1和Ii之间的回归关系）方法，其方法在模拟时候表现更好，根据原文表2的描述，每年单独率定的参数（原文表3）在日尺度上模拟streamflow的NSE能达到0.36，而对比基准的两种方法分别是0.13和0.28

## Integrated hydrological modelling of small- and medium-sized water storages with application to the upper Fengman Reservoir Basin of China （2012） 

这篇基本思路是尽可能利用可以使用的数据信息来对流域中小水利工程的蓄泄能力进行建模，主要是利用Landsat的数据，和针对不同大小的截流河调节能力水利设施的一个经验库容分类方法和一组水库库容下泄经验关系，来改进SWAT2005模型模拟能力。

案例分析就是放在了中国东北丰满流域，该流域有很多为了灌溉，工业用水和生活用水而建的中小蓄水工程。将改进的SWAT2005与原始的模型对比分析。

具体方法上说，因为有成百上千的小水库，不可能在一个模型中对每个小水库一一建模的，所以采用一种**聚合**的方式，在大尺度流域范围内合理的**模拟中小水库群的蓄泄行为**。

不同级别的水库的处理方式是不同的，大型水库有详细的设计和调度信息，但是小型水库只有行政级别的地理位置，流域面积，库容等基本信息。对于塘坝，那就只有流域级别的流域面积和库容量了。因此要**对水库按库容进行分组**。

选择SWAT模型是因为**SWAT包括水库模拟模块**，可以在流域尺度评估storage的影响。SWAT的水库模块就是水量平衡公式。计算的时候需要**水库的面积、库容**数据作为计算基础。SWAT本身有这个模块，但是**不同水库的slopes, storages, and drainage areas不同，面积库容关系不同**，统一采用一种计算方式不太合理，因此依据drainage areas与storage volume的比例也要对**不同水库等级分别估计**。具体方式上，Landsat主要是用来处理水体表面积；有了表面积之后可以进行面积库容关系的分级建立。

在分析河道水量平衡方面，河网中的水量平衡和运输公式通过**串并联**关系，整合流域拓扑、水库、用水等构建。采用了大小水库分开运算的方法：大水库就在模型中标出来，真实位置处理；小水库采用聚合的方法计算，每个等级的水库是并联的，不同等级间串联。

模型率定同时考虑自然和人类用水的因素，用水数据难以获取，所以表达为参数，使用率定的方式处理。文章认为用水的空间分布是和land use及天气情况相关。分了两个时期，分别对pond，reaches和shallow aquafers定义了参数来表示。

前面这三段的内容，在模型里面是相互之间有联系的，在模型里表达会统一到一块的。具体实现上，个人是这么理解的，大水库划分好子流域，每个子流域，小水库在模型外面就能耦合，class1-3的处理在外面就能处理好，然后输入到SWAT里面的表达class4-5的水库模块（原文图2）。

原文图7展示了计算对比结果，可以看到S1（文章提出的方法）的结果是优于S0（SWAT原装表达水库的模型）的，每个子图的NSE都有提高。

## On an improved sub-regional water resources management representation for integration into earth system models (2013)

这是一篇水库调度规则编入ESM （earth system model）相关的论文。主要目的是分析各种generic operating rules的水库模块的不确定性对于理解regulated径流、水库库容以及需水的影响。

具体来说，包括：

- 明确现存的generic reservoir operation rules 表现多好，subregional,regional 尺度上的模型性能什么样
- 大流域结合灌溉和防洪调度规则有帮助么
- 水库模块对调度规则、自然径流vs调节径流率定、消耗性用水vs取水的敏感性

具体方法是分initialization和simulation两个阶段。
初始化阶段，用VIC和MOSART（产汇流）计算得到每个subbasin（水库为出口断面）的自然径流作为水库入流。 inflow和demand一起作为用来设置调度规则。demand是从一个需水模型（从USGS用水报告分解到这篇文章关心的月、日尺度上）计算得到的。

模拟阶段，WM（water management）即水库模块加入到routing model，由runoff，baseflow和demand驱动。不同的调度规则只是WM中的规则不同，其他都一样。

WM中先从routing model里面的subnetwork取水，不能满足的话就从main channel取水（至少要留50%），还没完全满足，再从水库取水（可以取水的水库由一个数据库指定 demand portioning），从多个水库取水的时候，按库容比例分配。反过来对一个水库，如果不同的subbasins都对他有需水，那么根据另一个数据库（一个水库可供应的流域 dependency database），按subbasin需水的比例实际分配给各个子流域。也就是说，这块有个小小的交互，先是流域要水，然后水库了解后，分配供水。这个模块是offline的运行的，所以是一遍交互，应该没有更多的循环。

对水库，有了实际的demand，结合调度规则就可以给出过程了。调度规则是Hanasaki那一套，第一步是用年均径流做pre-release；第二步用月均径流和需水来修改pre-release；第三步用一个水库相关的系数来修改获得最终release。后面谈到的irrigation还是flood control对调度规则的改变，改变的都是这几步的公式里涉及的变量；还有i选择自然径流还是调节径流的均值以及demand选择withdraw还是consumption，改变的也都是这些公式，作者总结了一个表3可以看到所有改变。

水文模型的评价基于模拟的natural flow和观测值之间的error；整体模型评价是基于模拟的regulated flow和reservoir storages与观测值之间的误差，此外还评价了观测的consumptive demand被满足的程度。

看结果，我暂时主要关注flow的情况，对natural flow，VIC model的效果是不错的。比如The Dalles， natural flow的模拟NSE可以达到0.91，但是对regulated flow，最好的情况也只能达到0.62，其他的水库都是负数了。其他本文更重要的结果对个人暂时不重要，先不看了。

## Quantifying and generalizing hydrologic responses tp dam regulation using a statistical modeling approach (2014)

这篇文章主要是几个属性的选取对我有启发，暂时不细说了。

## On inclusion of water resource management in Earth system models Part 2: Representation of water supply and allocation and opportunities for improved modeling （2015）

这篇文章是关于在LSM或GHM中表达人类活动影响方面的两篇姊妹篇综述的第二篇，主要讨论了water supply and allocation在LSM或GHM中的表达。

在水库方面。

首先，为了表达它，需要在grid或sub-grid中给它位置，这方面数据集是比较多的，比如GRanD现在已经有超过30000个水库了，但是关于水库的storage，release，还有更多的physical characteristics，像库容面积深度取消，都是不能获得的；这些数据都是基于一些假设用参数化的关系公式表达的，还有水库模拟也很难直接验证，因为没有水库的大范围的水位和库容数据，这些可能能通过卫星任务来一定程度地改进。

其次，在表达水库的算法方面有两类型。一是模拟：1. Hanasaki 2006年的论文是一篇很重要的文章，基于规则，考虑需求和入流等在月尺度上能在ESM中模拟水库运行；2. 使用parametric functions来表达reservoir release，即可以使用观测的下游径流来率定水库相关的参数。比如前面提到的根据入流和水位基于特征水位和需求变化，结合参数来表达它们和出流之间的关系，从而模拟release。二是优化：这方面的一个早期重要文献是Haddeland 2006年的文章，基于未来未来一年的入流和需求，构建各调度目标，配合调度约束，利用优化算法来求解release的过程。他们主要研究的都是大尺度的人类活动影响，不是单纯的模拟水库对径流模拟或预测的影响，所以这里就不放结果了。

改进方面，包括不确定性量化；亚网格尺度的模拟；以及机器学习等方法来挖掘系统响应和需求之间的关系。

## Integrating a reservoir regulation scheme into a spatially distributed hydrological mode (2016)

主要是讨论了如何将水库调度包含到一个分布式水文模型中。

虽然水库的蒸发计算是基于面积的，但是水库还是表达在模型的一个grid cell中的，且在这篇文章用到的DHSVM模型中每个river segment只能有一个水库。考虑到DHSVM的高分辨率，river routing构建是用能包含多个grid cells的river segments的。

水库输入是上有入流和区间降雨，水库模块计算的是出流（release scheme）和库容（水量平衡）。

水库模拟包括蒸发模块，泄流模块和库容平衡计算：

- 蒸发计算依赖于面积的确定，以及彭曼公式。
- 泄流模块采用调度规则，水位控制调度，考虑需水和部分约束，需水模块可以通过率定的方式确定。
- 最后水量平衡的计算

水库模块和DHSVM的耦合是通过在dam所在的grid cell中使用水库模块实现的，分布式的做法中，不是将水库整个lmup到流域上的。

在DHSVM中，river channels是由connected river segments表达的，加入水库之后，river segment就被拆成上下游了，到水库这里公式换成水库调度的，然后下游再续接水库出流。这篇文章的code应该在这里有类似的版本：https://github.com/xdli1991/DHSVM_Res_8d

DHSVM模型是PNNL开发的：https://github.com/pnnl/DHSVM-PNNL

作者在Lake Whitney流域做了实例分析，有两个水库。DHSVM中soil和vegetation的参数需要率定，水库模块中水库的参数需要率定。结果显示，表2里面，Lake出流在日尺度上NSE分别为0.74和0.51. 

此外，作者在水库影响方面作了较多分析，详情可见原文，这些分析对science更有帮助。

最后，因为个人对分布式模型也不熟悉，所以简单记录下这个模型的输入有什么：

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

## A neural network based general reservoir operation scheme （2016）

这篇文章在聚合水库data-driven分析方面给予了我们一些启示。

## The impact of lake and reservoir parameterization on global streamflow simulation (2017)

这篇文章也是在grid上对水库建模，嵌入到LISFLOOD模型中，LISFLOOD是一个半概念半物理模型，在其routing scheme的river channel里加入了湖泊和水库模块。湖泊直接结合weir equation和水量平衡公式等分析；水库基于水位控制的调度规则来模拟，因为缺少运行相关的数据，因此都是假设了一些参数，比如最小库容，normal storage和最大storage（这三个值是原文水库调度公式里面的三个量）都是按总库容的0.1，0.3和0.97来的；再比如最小，normal和non-damaging outflow假设为日自然径流的5%，30%和97th percentile。

其结果有分析加入lake和reservoir之后的影响，在全球390个湖泊和水库的分析中，加入水库能提高65%的流域径流预测（NSE提高值中位数为0.16），但也降低了28%的（NSE减少值中位数-0.09）。原因就包括由于缺少调度规则相关的特定知识而对水库参数的粗略估计带来的不确定性影响了径流预测性能，这也是将水库模块嵌入到水文模型中但性能并不优秀的一个重要原因。

## Deduction of reservoir operating rules for application in global hydrological models （2018）

这篇文章是利用神经网络结合模糊规则ANFIS adaptive-network-based fuzzy inference system，在不同地区的11个水库上拟合了调度数据（linking inflow and storage with reservoir release）。结果发现，大水库调度更看水位，小水库则看流量。推求的规则能用来模拟水库出流，月尺度模拟的NSE平均值可以达到0.81；这时候Hanasaki的方法也能到0.42

## Modeling and simulating of reservoir operation using the artificial neural network, support vector regression, deep learning algorithm 

三个机器学习算法来模拟水库运行，不同时间尺度－－月／日／时，模拟30年的水库出流。

在葛洲坝水库的实验结果显式水库调度过程是可以被拟合的，在所有时间尺度上都表现除了极好的效果，LSTM NSE值都能到0.999，同时ANN和SVR最好分别能到0.98，可能是因为葛洲坝是个径流式电站，基本上入流有了的话，出流也就很容易得到了。

## Representation and improved parameterization of reservoir operation in hydrological and land-surface models (2019)

这篇文章介绍了一个general parametric reservoir operation model，思路还是基于调度图的水位控制思路。参数可以有general的，也可以通过率定的。在全球37个水库验证，并将其放入了一个叫做MESH的large-scale H-LSM，结果表明该模型能较好地表达水库，并且是generic的，能嵌入H-LSM中。

这篇文章很好地综述了之前的这类研究。作者将以往研究大致分为四类：

一是 Natural lake methods。这类方法是最简单的，即用lake的表达来表达水库，没有人为调度。release直接是水库库容的函数，参数取经验值。

第二类是 inflow- and demand-based methods。考虑inflow和demand来确定release，参数化公式，这样没有数据的情况下，可以通过率定的方式处理。典型的比如上面 Wisser 2010的文章；Hanasaki 2006的文章；

## Investigating the impact of manmade reservoirs on large-scale hydrology and water resources using high-resolution modeling （2019）

Sanghoon Shin的博士论文，专注于做水库影响的径流建模。

### Abstract

由于计算力等的提升和对问题了解程度的进展，现在的研究比较青睐 hyper-resolution global hydrological models。增加的空间分辨率带来的优点之一是能清楚地表示哪些是人造水库，哪些是自然系统导致的；不过目前的global models是不能模拟以整体的形式表示 river-floodplain-reservoir inundation dynamics 的。这就是这篇博士论文的主要目标，即开发一种high-resolution, continental-scale 的模型来模拟水库蓄泄的时空动态，来为大陆尺度或全球尺度的水文气候模型的超分辨率地表水建模铺垫。相比于以往的global reservoir modeling 研究的优点：

1. 通过解析分析和数值实验并引入对水库调度的新的率定特点，改善了现有的水库调度算法
2. 显式地模拟水库的空间范围和季节动态，将水库当作 river-floodplain routing 的一个有机部分，使reservoir storage 不再孤立于river 和 floodplain storages。
3. 给出了一种处理整合高分辨率DEM到river-floodplain-reservoir routing 过程的新方法

这个新开发的水库模块被整合到一个水文模型LEAF-Hydro-Flood 的river-floodplain routing scheme；然后 水库模块整合到一个水动力模型CaMa-Flood来研究实际案例的水库的影响。

文章目录结构大体上是这样的：

- introduction 介绍研究的基本框架，motivation，goal等
- High-resolution Modeling of **Storage Dynamics** at the Continental Scale
- Development of **an Improved Reservoir Operation Scheme**
- **Sensitivity Analysis** for the Effect of **Upstream Flow Regulation** on **Flood Dynamics**
- Impact of **Manmade Reservoirs** on Mekong River Basin Hydrology over the Past Years
- 总结

前两章是开发模块，后两章是应用。

### Introduction

首先背景，总之是一些水库建设及其影响还有研究意义的概述。

首先第一部分主要内容，即High-resolution Modeling of Storage Dynamics at the Continental Scale。水库调度蓄泄决定的方式是较难表达的，一般是用一些常规的调度模式来在水文模型中表达，也有用神经网络来表达的。虽然它们取得了一定效果，不过在表达时空动态以及和hyper-resolution的水文模型联系方面还可改进，主要是四个方面：

1. 大多数schemes针对的水文模是宏观尺度的（使用粗网格来表示水库），高分辨率的还没有
2. 现有的scheme不能显式表达水库动态
3. 现有的schemes没有为regions的river, reservoirs, floodplain 整合考虑
4. 有必要更好地利用tepography数据，尤其是更好地表示river和reservoirs的高程数据（现有的DEM有些是有极大误差的，会造成使用时结果不稳定），并将其与hyper-resolution的模型一致起来。
 
 
第二部分，是新的高分辨率reservoir scheme在湄公河流域的应用。湄公河上水库的影响研究已有不少，但是都是基于不同方法各自角度出发的，比如基于观测数据来识别明显水文变化的，基于水文分析的，基于水动力分析的等。需要一个整合的角度来分析。

整体上研究目标还是想为更广泛的变化环境下的食物、能源、水系统可持续性研究提供价值。所以这篇文章基于以下两个方面具体的问题展开分析：

1. 高分辨率global 水文模型的reservoir scheme 的开发
    - 在高分辨率的大陆或全球尺度更好地表达 river-reservoir-floodplain storage 的技术上挑战和机遇
    - 在large-scale模型里如何使用有限地可用地信息来更好地模拟reservoir release
2. 大坝对land hydrology和水资源的影响
    - 新大坝的径流调节对下游洪泛区动态潜在的影响
    - flood 动态在调节流域水文的角色是什么
    - flood 动态和地表water storage是在过去四十年是如何变化的
    - dams的作用和气候变化相比影响显著么
    - 现存的水库在调节surface water storage 和inundation dynamics的角色是什么

具体的目标就是：

1. 开发一高分辨率的水库scheme来表示水库库容的动态，作为整体的river-floodplain routing的一部分，用到全球水文模型GHMs，地表模型LSMs和地球系统模型ESMs中。在CONUS上的研发。
2. 调查增加的大坝在气候变化条件下对地表水文水资源的影响。在湄公河的实验。

### High-resolution Modeling of Storage Dynamics at the Continental Scale

注意主题是 storage dynamics

整合水库模块到LEAF-Hydro-Flood，进步的方面有：

1. 空间范围和水库的季节性动态显式表达，水库被当作river-floodplain routing的一部分整合。
2. 新的在routing中处理DEM数据的方法

新开发的LHFD模型在CONUS上的测试，是在5km网格上进行的，利用了river flow，reservoir storage，和water use数据。

本章第一部分首先介绍LHFD模型，DEM处理，routing 模型和率定方法；第二部分展示高分辨率 river-reservoir-floodplain storages 结果。

首先看水文模型 LEAF-Hydro-Flood-Dam(LHFD)。这是一个经典的水文模型，从4个部分模拟energy和water storages:canopy air and vegetation; bare soil surface; 14 soil layers, river-floodplain

目前routing模块是质量方程和动量方程，数值求解该方程时候分辨率选择上是有权衡的，时间分辨率上要满足Courant-Friedrichs-Lew，空间上网格点在计算时间和精度上权衡。

有一个challenge是Storage Buffer Effect，个人理解是因为现在很多表达水库是在一个网格中，目前的约束就是其下泄是由调度规则来控制的，另外就是下游和它在水力学上是隔离的，只有调度之后才有联系。但是这些约束不足够，因为这时候的模拟是高度依赖DEM的（方程上可以看到），在水库附近的上游网格会缓冲水库网格的storage，导致蓄水过程偏慢，不能准确表达水库的季节性蓄泄过程。这在DEM准确的时候是不会出现的，它是一个虚拟的计算现象，假设水库和上游网格之间高程差很平，那么水库上游河道网格的蓄水量就会和水库有可比性了，这时候SBE就会明显。因此处理SBE是比较重要的。

处理的方式是首先改进river-reservoir河床和floodplain的高程，通过给reservoir 边界的约束。边界上的非水库cell的水位和水库cell的bed level之间的slope用作水库和非水库cell之间的routing的接口的potential energy gradient。

以上是一些基本方法的介绍，在数据处理上，水库的数据来自GRanD数据库，模型DEM生成的水库位置的流域面积和GRanD数据库不一致的，会将水库位置调整到和GRanD数据库匹配。在文章开发的水库scheme中，reservoir storage不再聚合于一个网格，而是spread到上游多个cells中，最大的水库范围对应最大的库容，然后能考虑季节性的表面积的变化。

关于water use data，USGS提供了每5年一个的平均用水数据，但是模型需要的是daily到monthly的数据，因此需要将USGS数据在时间上分解到月尺度。怎么做的？通过一个1度分辨率的global model HiGW-MAT模拟月尺度的irrigation water patterns，然后用这个数据来分解。HiGW-MAT模型利用irrigated areas，crop types和crop calendar的信息来获取monthly irrigation demand。每5年的一组数据用来计算monthly irrigation fraction。除了灌溉之外的需水被假定变化不大，因为只有灌溉相对是比较有季节性的。这样就能将5年平均数据分解到月尺度上。

根据以上内容，可以得到每个county的月尺度用水时间序列，不过还需要将用水分配到水库。因此将county的数据regridded到模型的5km grid上。每个水库需要满足水库一定距离范围内下游区域的用水。这个范围不同的研究有不同，这篇文章用了200km作为范围。为了防止过量分配需水，给了一个0.8的DPI(demand per inflow)上限。

然后是river-reservoir bed 和 floodplain elevations 数据。因为整合的river-floodplain-reservoir routing是需要可靠的terrain data来表达bare-earth elevation。为现在的水库获取这样的数据是很有挑战的，因为可用的DEM提供的关于水库的高程仅仅是water surface elevations。这个是比实际上水库bed elevation要高出几十到几百米的。有些高程数据可以提供信息，但是只能给一些水库提供帮助。这里为了解决数据限制，推求reservoir bed elevations，首先假设：

1. 水库位置处会发生一个河流流向方向上的高程突变，它是和dam height接近的。
2. 大多数河流都有一个下凸的高程纵断面的，即河床高程高到低的整体变化趋势是在的。

为了推求 river-reservoir bed 和 floodplain elevations，使用了MERIT DEM(Multi-Error-Removed Improved-Terrain DEM)，它是基于SRTM DEM，但是包含了多种errors corrections，使用了多个卫星数据集和filtering 技术分离绝对误差、stripe noise、speckle noise 和 tree height bias。另外，还有SRTM DEM的topography slopes的distortions 和 其他的inconsistencies 也通过误差消除方法改进。因此MERIT DEM是比较合适用于 terrain-dependent 水文应用的，比如reservoir-floodplain simulations。关于流向，没有从DEM生成，而是直接使用了HydroSHEDS 的数据，因为模型用的网格和HydroSHED给出的还是不同，所以需要在模型分辨率尺度上给出流向，一个网格周围8个，根据一定规则选出上下游网格。

因为MERIT DEM 不提供river-reservoir bed elevations，尤其是水库存在的地方，因此设计一个新算法来推求reservoir bed elevations。

1. 首先，先根据DEM获取河段内各个cell的最低高程
2. 然后用指数函数形式拟合一个上下游高程关系
3. 用滤波函数平滑高程

以上是关于river-reservoir bed 的高程。然后是关于floodplain 的高程。

在模型中每个cell都是被认为矩形河道断面的。超出河道的水被认为是均衡分布在flat 的floodplain上的。不管是水库还是非水库的cell，都是有一个river-reservoir bed高程和flood plain高程，bed和floodplain高程在一个grid cell内假设是flat的（个人理解，就是一个有两个翅膀的矩形水槽，两边一样高，中间是bed，断面是矩形的）。水库和非水库的cells是被一样建模的，水库的信息只是被用到reservoir storage上。

FLoodplain 高程由DEM推出，以climatological equilibrium water table（EWT） 作为基准。即当5km的cell由多个DEM的像素，那么假设低于EWT就代表永久性河流，高于EWT的DEM的均值就是flood plain的高程了。

水库库容水位关系用一个倒三角的形状表示，即 $V=ah^3$ （注意，这和上面断面形状并不矛盾），观测到的DEM作为flood plain的高程。然后将floodplain 高程调整到满足上述关系。

最后是atmospheric forcing 和其他参数数据。

结果展示就是reservoir storage对应的网格的水深。从文章结果的图上可以看出还是很好的识别出了水库的，水库的地方水深会比较明显。

总结下主要是完成了一个CONUS上5km grids上river-reservoir-floodplain storage的模拟。首先，处理DEM的时候用的是河床高度；其次，水库下游的water use数据拆分到月尺度了；然后SBE的问题的处理。

可能有些概念第一次不太好接收，可以先继续下一章节，再来看。

### Development of an Improved Reservoir Operation Scheme

基于前面的storage表示和一个水库调度的scheme提出一个新的改进的水库调度scheme，并整合到LHFD模型中，并给出新的率定方法。

改进的水库调度scheme是这样的。总体上分为三步骤，首先是估计一个初步的年下泄量体现年际差别，然后是初估一个月下泄体现年内差异，最后再给出各月径流。其中基于初始库容确定年下泄总量，并考虑water use来表达月下泄变化。

调度是按调度年给的，每个调度年定义，是以月均径流从高于年均径流变化低于年均径流那个时候开始。

具体scheme是这样的（前面已经给出了，这里重复下）

首先定义一个下泄系数，
$$k_{rls}=\frac{S_0}{\alpha C}$$
它可以表达每个调度年之间的变化性。基本的逻辑是这样的，一年的总供水量很大程度上取决于初库容以及长期目标需水，长期目标水量用库容乘以一个系数表达，所以可以得到上式。

那么早期的关于第y年总release的初步假设值可以设为：
$$R_y \approx k_{rls} * \bar {i_m}$$

然后给出一个临时的月下泄值：
$$ r_m' = \bar {i_m}+d_m - \bar {d_m} \ \ \ \ \ \  \ \ \ \ \ \   \ \ \ \ \ \    if DPI<1-M$$
$$r_m' = \bar {i_m}(M+(1-M)d_m / \bar {d_m}) \ \ \ \ \ \  otherwise$$

其中，DPI是年均需水和年均径流的比值，M是最小月下泄和年均径流的比值。

这里的基本逻辑是对于需水相对不多的情况，即第一个公式，使用均值分配的方式初步分摊到各个月体现月内差异。对于第二个公式，对应的是需水相对较大的情况，应该使用一种类似hedging 的方式，可以看到$d_m$的系数，计算下为$(1-M)\frac{\bar {i_m}}{\bar {d_m}}$，是小于1的，也就是分配到的需水并不都满足。

最后目标月下泄可以由下式计算：
$$r_m=Rk_{rls}r_m'+(1-R)i_m$$
这一部分主要是再考虑库容 来最后定义月下泄。库容够大，即R=1，那么可以直接将初估的下泄乘以下泄系数即可，就如开始初设的年总下泄那样。当R<1时，可以计算下，即$r_m=Rk_{rls}[(1-M)\frac{\bar {i_m}}{\bar {d_m}}d_m+M\bar{i_m}]+(1-R)i_m$，可以看出还是一个关于demand的线性函数，系数还是小于等于1的，所以这里可以看到对应一种二点hedging。

这篇文章主要改进的地方就是

- 使用了DPI<1-M 来防止high demand时候的excessive release 
- 使用了R=min(1,$\alpha$c)代替了R=min(1,4$c^2$)

这部分作者的分析不太好懂，这里就详细翻译下。

第一个 DPI<1-M ，已有的是DPI<0.5。 high DPI 意味着水库更容易干旱，所以是有对冲的意思的。（除非对DPI<1-M进行适当的修改，否则下泄的variability会被放大而不是减弱。）为什么要DPI<1-M：

根据前面两式：
$$ r_m' = \bar {i_m}+d_m - \bar {d_m} \ \ \ \ \ \  \ \ \ \ \ \   \ \ \ \ \ \    if DPI<1-M$$
$$r_m' = \bar {i_m}(M+(1-M)d_m / \bar {d_m}) \ \ \ \ \ \  otherwise$$
可以推求：
第一个公式下最大值和最小值分别是：
$$r_{max,a}' = (1+(D_{max}-1)DPI)\bar{i_m}$$
$$r_{min,a}' = (1+(D_{min}-1)DPI)\bar{i_m}$$
D是$d_m / \bar {d_m}$，推导就是简单的变换，这里就略了。
$$r_{max,b}' = (M+(1-M)D_{max})\bar{i_m}$$
$$r_{min,b}' = (M+(1-M)D_{min})\bar{i_m}$$
那么两部分最大、最小之间的差值(直接减，合并同类项即可得到)：
$$\triangle _{max}=r_{max,a}'-r_{max,b}'=(1-D_{max})(1-M-DPI)\bar {i_m}$$
$$\triangle _{min}=r_{min,a}'-r_{min,b}'=(1-D_{min})(1-M-DPI)\bar {i_m}$$
最值之间的比较是什么意义呢？个人理解，比如最大值，就是需求最大的月份，两种表达之间本质上应该更倾向于选择第二种，文章里面使说if the use of equation (3-2b) enables less variability in release, max? and ? should be positive and negative, respectively，又因为$D_{maax}$显然是大于等于1的，$D_{min}$显然是小于等于1的，且$\bar {i_m}$是大于0的，所以就知道条件判断是什么了。

我的理解是这样的，因为需求越大，越有可能导致后期供水不足，所以这时候应该选择hedging的那个，既然是hedging的，那么根据$r_m' = \bar {i_m}(M+(1-M)d_m / \bar {d_m})=\frac{1-M}{DPI}d_m+M\bar {i_m}$，应该有DPI>=1-M，才能使直线系数小于1，所以第二个公式的条件是DPI>=1-M。

关于第二个R=min(1,$\alpha$c)。这篇文章主要是代替了$R=min(1,4c^2)$。分析的开始依然是基础的水量平衡公式。
$$S_{target}=S_0+\bar{i_m}*(1 year)-k_{rls}\bar{i_m}*(1 year)=S_0+\frac{C}{c}-\frac{S_0}{\alpha C}\frac{C}{c}=S_0(1-\frac{1}{\alpha c})+\frac{C}{c}$$
这个公式是怎么有的，因为目标库容就是末库容，初库容和入流都没什么说的，主要是下泄，这里因为是用下泄系数来表达下泄和入流之间的关系，而下泄系数是用初库容和一个长期目标库容之间的比例作为surrogate的，这就是公式的来法，注意下泄系数是一个前提定义，为了得到一个比较general的调度模式，需要这样一种方式。

根据出流系数的表达，$k_{rls}=\frac{S_0}{\alpha C}=\frac{\bar{r_m}}{\bar{i_m}}$，所以$\frac{S_0}{\alpha}\frac{\bar{i_m}}{C}=\bar{r_m}$，其中，$\frac{\bar{i_m}}{C}=1/c$，那么初storage变化1/c的变化对应的是平均出流的变化。c大时，出流变化对应storage变化小。

我自己的理解就是c越大，就是说库容(对水库来说是已知的定值)相对于入流越大。而看水量平衡公式，当系数$1-\frac{1}{\alpha c}$大于0时，表示的意思是初库容越大，末库容也越大，在demand一定的条件下，这是比较符合逻辑的，否则初库容越大，末库容越小，不合理。即$c<\frac{1}{\alpha}$。这时候需要设置一个R来帮助使库容变化更加合理。即让c和$R/\alpha$比较的时候变大，所以有$R<=\alpha c$，这样就得到了R=min(1,$\alpha c$)

为了比较R=min(1,$\alpha c$) 和 R=min(1,$4c^2$)，根据两个曲线的交点等，将R和c的关系图分为了四个区域，分别比较。IV区不需要R，I区差别不大，II和III区，尤其是III区，明显后者是不能有满足条件的R的。

在计算中，能率定的就率定R，不能率定的才使用公式。模拟中，梯级水库本来是上下游有影响的，要一次性全部计算下来，然后迭代计算更新参数比较好，但是这样就难以进行，所以就从上游到下游依次率定。一个水库的入流是由上游所有有大坝和没大坝河道出流的汇流结果，但是公式不是特别理解，因为有一个比例。

然后是结果。

## On the representation of water reservoir storage and operations in large-scale hydrological models: implications on model parameterization and climate change impact assessments （2019）

## Real-time reservoir operation using recurrent neural networks and inflow forecast from a distributed hydrological model （2019）

## Comparison of generalized non-data-driven lake and reservoir routing models for global-scale hydrologic forecasting of reservoir outflow at diurnal time steps （2020）

## An experiment on reservoir representation schemes to improve hydrologic prediction: coupling the national water model with the HEC-ResSim （2020）

