# Evapotranspiration and Consumptive Irrigation Water Requirements 计算细节

前面的1，2里面还有一些更细节的内容没有涉及，这里再根据：[Evapotranspiration and Consumptive Irrigation Water Requirements for Idaho](http://www.kimberly.uidaho.edu/ETIdaho/)以及[FAO-56 Dual Crop Coefficient Method for Estimating Evaporation from Soil and Application Extensions](https://ascelibrary.org/doi/full/10.1061/%28ASCE%290733-9437%282005%29131%3A1%282%29)补充一些。

## 报告概况

计算过程包括ASCE PM公式计算reference ET，以及用一套考虑灌溉和降水影响的新方法计算了crop coefficients。计算对象是天气站，天气站包括National Weather Service（NWS）的站点和AgriMet的站点。日尺度的ETc的计算能够考虑降雨或灌溉事件之后的蒸发计算，准确性更好一些。

大部分crops的growing seasons的starts 和 durations 是每年每年依次决定的，依据是开始日期前30天的平均气温以及season开始后的growing degree days。Growing seasons 的结束是通过 killing frost 或者 预测作物的maturation 来确定。**基准Kcb曲线用相对时间尺度或相对热单位尺度表示**，以便Kcb曲线每年根据天气情况进行不同的拉伸。依据crop或者land-use的类型，四种不同的方法用来表示基准Kcb曲线：

1. percent time from planting (or greenup) to harvest; 
2. percent time from planting to effective full cover, with this ratio extended until termination;
3. percent time from planting to effective full cover and then days after full-cover; and 
4. percent cumulative growing degree days from planting to effective full cover, with this ratio extended until termination.

具体信息后面来看，

用于估算裸地湿土蒸发的FAO-56方法被用于计算10厘米土壤的日水量平衡，作为在土壤表面干燥时减少蒸发损失的一种手段。在灌区，为了估算湿土壤表面的蒸发量，对典型的灌溉作物进行了灌溉模拟。灌溉Scheduling采用root zone水量平衡，假设root zone不受限制，土壤水分耗竭到允许的耗竭水平。模拟灌溉Scheduling典型地类似于那些与地面灌溉和手摇或轮毂线喷灌系统(即“低频率”)实践的灌溉计划。利用国家国家土壤信息数据库的信息，利用GIS分析每个站点指定区域的数据库，确定了每个站点的有效持水量和土壤质地。采用NRCS曲线数法估算降水径流，其中前期水分由每日表层土壤水分平衡计算。以StatsGo土壤数据库为基础，根据土壤纹理确定曲线数。

在许多NWS观测站观测到的积雪数据被用来修正由雪的高反照率和融合热所需的能量所引起的蒸发的冬季估计，也被用于冬季小麦CGDD的调整。

## ET 计算主体过程回顾

ETc的计算依赖于 ETo的计算以及一个系数Kc。所以首先要解决ETo的计算问题。reference ET是指具有标准化统一高度、生长活跃、完全遮蔽地面、叶片表面干燥而健康浓密、不缺水的参考植被 extensive surface 的ET速率。这个定义通常用于 standardized reference crops of **grass (ETo)** and **alfalfa (ETr)**。（FAO56中用的是grass 的reference ET，本计算用的是alfalfa的reference ET）

ETc计算是针对某种作物的extensive surface上的ET rate。其受 crop growth stages，amount and frequency of wetting of the soil surface, environmental conditions 以及 crop management 的影响。当作物的叶子没有完全遮蔽地面或当作物开始成熟和衰老时，ETc通常比ETr要小；当作物已发育出大量的叶面积以及地面几乎全部地被cover的时候，ETc基本等于ETr。ETc单位是 mm/h , mm/d 等，和 consumptive use 意思等价。

ETc定义中的“extensive surface” 和计算方法要求作物覆盖足够大的面积，使作物表面的能量交换和作物上方的风速、温度和湿度profiles处于平衡状态。只有当这种平衡存在时，标准Kc ETr方法才能达到最高的精度。extensive surface 条件适用于field sizes大于200米(相当于4公顷(10英亩))。

ETr、Kc等计算采用每日时间步长计算，以提高精度。每日计算时间步用于计算降水或灌溉事件后从湿土壤表面蒸发的水。每月、生长季节和年度等的数据都从每日计算中总结出来。

计算Kc的方式有两种，一种是长期的平均Kc，under some “average” wettomg interval的值。另一种是Kcb+Ke，更适合日尺度计算，Ke能反映wetting event的作用。
$$ET_{c\ pot}=(K_{cb}+K_e)ET_r$$
代表了potential ETc，即when the soil surface layer is dry, but where the average soil water content of the root zone is adequate to sustain full plant transpiration 条件下的Crop ET

不过when soil water content is less than that able to sustain full rates of evapotranspiration 时，实际ETc 会比potential ETc要小，所以还需要一个a stress coefficient
$$ET_{c\ act}=(K_sK_{cb}+K_e)ET_r$$
灌溉作物在生长季节或典型灌溉季节以外的时期，以及雨水灌溉作物或土地被覆盖作物在降水不足以满足ETcpot rate时，Ks值可以降低到1.0以下。需要一个日土壤水量平衡来计算Ks，因为其值会随着soil water contents的减少而改变。这种土壤水分平衡包含了在生长季节某一特定日期模拟的the full effective root zone。另一个与之不同的水量平衡用来计算Ke。在这个水量平衡中，仅仅模拟 0.1m 表面土壤。

Ks和Ke的水量平衡计算都是基于FAO56的记录。与FAO56不同的是 reference ET用的ETr。另外，本文用的是curvilinear Kcb curves，而不是FAO用的the linear-style of curves。因此，估计$K_{c\ max}$和Kcb的方程也和FAO56 2005年扩展版不同。当使用Etr时，不需要调整$K_{c\ max}$和Kcb。

The Crop Coefficient Curve 表示了 growing season 中 Kcb的变化，取决于vegetation cover 和 maturation 的变化。曲线通常在growing season开始时较小，随后逐步增大到full cover，之后由于叶子老去减小。

Kcb曲线是Kcb值与时间（日期或者年内儒略日数）的函数。生长季节的开始时间、生长季节的持续时间和生长季节的结束时间每年都会因 **春季的温度条件和heat availability(即 growing degress days)** 而有所不同。因此本文中，大多数作物的生长季节开始和持续时间是根据开始日期前30天内的平均气温和开始季节后的growing degree days 的比例逐年确定的。生长季节因作物的成熟日期或致命霜冻而终止。

稍微补充一点关于GDD的基本概念，主要参考：[GROWING-DEGREE DAYS AND DEVELOPMENT
OF THE WHEAT PLANT](https://cropwatch.unl.edu/documents/gdd.pdf)。作物生长的因素肯定是非常复杂的，受温度，光照，水，营养等各种因素的影响，不过有一些简单的方式来描述plant development。可以根据植物leaf，tiller，root的生长来简单地定量植物地生长，这种方式就被称为 cumulative growing degree days。CGDD的计算是完全基于气温的，即从planting 到 present 每日平均气温中正值的累计和。它是一种衡量过去植物受热量的方式。对于冬季谷物，比如冬小麦，早春的温度通常是作物生长的一个限制性的因素，growing degree days就能给出一个对这一因素的直接的衡量。越温暖的话，作物就能为生长更快收集heat units。小麦是0度停止生长，玉米还有其他温季作物都在大约10度停止生长，这就意味着所有低于10度的时间都不被考虑为生长时间。所以当使用cumulative heat unit 的思路时，对于温季作物，要考虑使用一个base temperature 把 低于这个温度的时间从生长时间里cut掉。

为了使Kcb曲线每年可以不同地拉伸，根据天气情况，**基准Kcb曲线用相对时间尺度或相对热单位尺度表示**。基底Kcb曲线的表达采用四种不同的方法，稍后补充；另外，估计各种作物和土地覆盖类型的生长期开始时间的方法，以及由于杀霜而终止生长期的方法，也在稍后补充。

最后注意，所有的计算都是基于station的数据计算的，即使是需要面计算的，比如计算Available water holding capacity and texture of soil时，也是using information from the National StatsGo soils information data base using a GIS analysis of the national soil data base for **the area assigned to each station**，即有对应到station的area，在此上进行的选择，关于面积的选择稍后在Available water holding capacity计算的补充中会有记录。

## 特定作物ETc计算时还需要的各个计算模块简介

1. 用于估算裸地湿土蒸发的FAO-56方法应用于计算**土壤顶部10厘米的日水量平衡**.
2. 为了估计湿润土壤表面的蒸发量，在灌溉地区对灌溉作物的**灌溉进行了模拟**。灌溉调度采用root zone水量平衡，假设root zone不受限制，土壤水分耗竭到允许耗竭水平(MAD)。模拟灌溉计划典型地类似于那些与地面灌溉和手摇或轮毂线喷灌系统(即“低频率”)实践的灌溉计划。**灌溉在种植或绿化后的指定天数开始**(预先设定好)，并限定在Kcb < 0.22的发展期不灌溉，这样做是为了防止在根系带较浅的季节早期进行一系列频繁的轻度灌溉。
3. 每个站点的**可用持水量Available water holding capacity**和土壤质地是利用来自美国国家统计局土壤信息数据库的信息确定的，使用地理信息系统分析每个站点指定区域的国家土壤数据库(多边形)
4. 采用NRCS曲线数法估算降水径流，其中前期水分由每日表层土壤水分平衡计算。曲线数由StatsGo土壤数据库的土壤质地确定。
5. 在许多NWS观测站所观测到的积雪数据被用来修正冬季对积雪高反照率和聚变热所需能量所引起的蒸发的估计。在冬季调整冬小麦cumulative growing degree days时，还利用了积雪量。
6. 自然植被、紫花苜蓿、牧场、草坪和冬小麦的绿化时间和一年生农作物的种植日期用cumulated growing degree days or或30天平均气温来估计

## Crop and ET Modeling Parameters 补充说明

### Crops Grown

文中研究的Idaho州一些地区生长季节较短，这限制了可以种植的作物类型。其他地区传统上是雨养地区，这也限制了农作物的种类。根据传统和当前的作物生长情况，**为每个气象站分配了特定的作物和土地覆盖类型**。该州的作物种类和一般栽培面积列于原文表6。大致四类，general to Idaho， specific to Southern Idaho/Northern Idaho 以及  Natural land-use conditions 的。Natural land-use conditions 中的 bare soil, mulched soil and dormant turf是在估算非生长季节蒸发量时，用来给每种作物类型的非生长期的。

原文表7是作物参数的一个较全的表格，其中，crop curve types有四种，后面补充。

另外，表7中的“Irrigation Flag”表明是否假定作物是灌溉的，有灌溉的话会从湿润土壤增加了一些蒸发。灌溉标志为0表示作物或土地利用状况从未进行灌溉，而标记为3表示作物一直进行灌溉。灌溉flag等于1或2表示，如果作物在灌溉地区，就有灌溉，如果在一个通常没有灌溉的地区,例如在爱达荷州北部的大部分地区，就没有灌溉。

表7中“Flag for means to estimate pl or gu”标识了用于估计种植日期或greenup的过程。等于1的flag表示使用1月份起的cumulative growing degree days，等于2的flag表示使用30天的平均气温。

表8显示了在每个location建模的作物。如果表8中的值不等于1，则表示使用基于cgdd的标准方法估计的生长期长度的调整值。这些调整是为某些作物和在某些地区生产更具有实际操作特点的长生长期而作的。即计算CGDD时候，乘以一个系数调整下。

### Root Growth

根的生长被估计为the initial root zone（假设发生在种植或绿化时） 和 每个作物指定的 最大有效生根深度 maximum effective rooting depth 之间的时间函数。这两个值之间的根深度是用Borg and Grimes(1986)的sigmoidal函数估计的：
$$z_r = z_{min}+ [0.5+ 0.5 sin(3.03F_{time\ root} -1.47)][z_{max}- z_{min}]$$
其中，$z_r$为生长季节一个时间的有效根深度,$z_{min}$为起始有效根深度(在种植或greenup时)，$z_{max}$为最大有效根深度，$F_{time\ root}$是从根开始增长到最大根深度时间的比例。根深度变量可以用米或英尺作为单位。Borg和Grimes根生长函数如图所示：

![](QQ截图20200916212400.png)

## DEVELOPMENT OF CROP COEFFICIENTS

首先，是Growing Degree-Day Basis for Crop Coefficients。从planting 开始的CGDD是常用的计算crop 系数的基础，其可以自动调整生长期长度，和成长时期来考虑年际间温度的变化，并作为一种可以在区域间转移使用的方法。此法比日期法更接近crop实际收到的热量。

玉米的是30度以上不生长，10度以下不算：
$$GDD_{corn} = (\frac{max(min(T_{max} ,30),10)+ max(min(T_{min} ,30),10)}{2}) -10$$
大部分计算GDD的基础公式是：
$$GDD=max(\frac{T_{max}+T_{min}}{2}-T_{base},0)$$
为了使用ASCE-PM ETr方法创建crop系数，所以需要把之前的Kc time base 转换为 normalized GDD base。这个过程没找到文章，不过文中附录表里已经给了结果。

CGDD还要做一个归一化，得到NCGDD：
$$NCGDD=\frac{CGDD_i}{CGDD_{EFForTERM}}$$
$CGDD_{EFCorTERM}$是指定的和作物相关的CGDD值，时间范围是**从种植或绿化时起至达到有效的完全覆盖**，所以NCGDD在种植或绿化到有效全覆盖期间范围为0 ~ 1，在有效全覆盖到收获或灭霜期间范围为1 ~ 2。

将累积ET vs. 时间曲线（即累计ET与时间的函数关系曲线） 与当年计算的等效归一化CGDD和气象数据集配对，确定报告有效全覆盖时的CGDD值。NCGDD的计算方法是每天用当天的CGDD除以有效全覆盖时的CGDD。最后，从plots中选取Kcb的百分位值，NCGDD的数值增量为10%（百分之十的意思是Greenup 到 full cover的总时间的10%，而这些作物有的后期时间还很长，所以就会到300等，有的比较短，可能200就结束全生长周期了）。这个意思就是**通过有的ETc和ETo（有不同的计算方法，有ETr，有ETo）等值，来确定一个基础的crop 系数曲线，就能反过来推出来NCGDD，然后这个NCGDD与Kcb的关系曲线就能作为后面用来计算的基础**，这也是前面说 可以transfer的优点的实际意思。

冬小麦的CGDD计算有些不同，详见原文。

alfalfa hay需要特殊计算 individual cuttings。

为了应用 Kcb和NCGDD关系曲线，当然每年都需要新计算planting 或 green up 日期（后面还会有进一步补充），然后计算NCGDD，再来调整Kcb值。

第二类Kcb是Kcb based on Percent Time from Planting (or Greenup) until Effective Full Cover Applied all Growing Season。

还有一些作物的基本作物系数Kcb是使用其他标准化基准方式来确定的。比如基于从种植到有效全覆盖的标准化时间，参考原文表3.6。这个标准化的比率适用于整个生长季节。横坐标是Percent of Time from Greenup to EFC，纵坐标是Kcb

第三类是Kcb vs. Percent Time from Planting (or Greenup) until Effective Full Cover and days after Effective Full Cover。这一类和之前的区别就是构建曲线时候的那个基准时间范围是从 Planting 到 full cover之后几天。

第四类是Kcb vs. Percent Time from Planting (or Greenup) until End of Season。显然这一类横坐标就就只到 100%。

## GENERAL INFILTRATION CHARACTERISTICS AND WATER HOLDING PROPERTIES FOR WEATHER STATIONS

在ETc模型中，土壤入渗特性被用来估计来自降水的地表径流。土壤水分保持特性被用来估计预期的灌溉计划，据此估计来自土壤的蒸发损失，估计来自root zone的深层渗透，以及估计每次湿润事件的蒸散发的总深度。

合作的美国国家海洋和大气局站的位置已根据其报告的纬度和经度输入一个地理信息系统。利用ArcGIS 9.1**构建 Thiessen 多边形**，利用GIS系统将爱达荷州的区域**划分为每个气候站所代表的区域**。这些多边形上覆盖了美国农业部STATS-GO全美土壤覆盖率的土壤信息，以确定**每个Thiessen多边形区域的平均表面渗透性特征和上36英寸的持水能力**。

美国国家土壤地理数据库(State - go, State Soil Geographic Database)是一份数字式土壤协会地图，由国家土壤调查合作开发，描绘关于区域、多地区、河流流域、州和多州资源规划活动地表或附近土壤特征的信息。**数据库中的地理单元被称为绘图单元**。每个绘图单元**使用一个或多个土壤成分进行描述，这些土壤成分可能具有一个或多个层**。爱达荷州的state - go数据库中的各种土壤图单元(507)由2至20个土壤成分组成，其中各成分包含1至6个土壤层。每个组成部分在绘图单元内按比例分配。地表量化中所使用的土壤成分描述性数据为：

- comppct – Percentage of map unit described by soil component. 绘图单元各土壤成分的百分比
- slopel – The minimum value for the range of slopes for the component within the mapping unit (percent).
- slopeh – The maximum value for the range of slopes for the component within the mapping unit (percent).
- perml – The minimum value for the range in permeability rate for the soil layer (inches per hour). 
- permh – The maximum value for the range in permeability rate for the soil layer (inches per hour). 
- laydepl – Depth to the upper boundary of the soil layer (inches) 
- laydeph – Depth to the lower boundary of the soil layer (inches) 
- awcl – The minimum value for the range in available water capacity for the soil layer (inches/inch). 
- awch – The maximum value for the range in available water capacity for the soil layer (inches/inch).

每个土壤component上层36英寸的根区可用水量(AWC)是由上面36英寸（toor zone）每一层的最小和最大AWC加权平均(层厚度的权重)计算的。两个值之间平均来获取soil component的midpoint AWC。

然后以坡度和water为基准，采用5个类别对一个制图单元和气候站区的土壤特征进行了汇总。

![](QQ截图20200917094013.png)

根据各组分在土壤绘图单元和气候区的面积范围，对土壤midpoint  permeability、AWC和“root zone”进行了加权。气象站多边形的估计值由每个坡度分类的加权中点确定。并得到表征参数的最大值和最小值。

在一个绘图单元中，土壤成分的渗透性估计是基于土壤成分的第一层来表示控制水的渗透的表面特征。将渗透率范围的低值和高值相加平均，得到以英寸/小时为单位的中点渗透率估算值。在全州范围内，表层土壤的平均最小厚度在2到8英寸之间，平均最大厚度在11到53英寸之间。气候站区第一层的整体平均厚度在6到21英寸之间。

USDA-NRCS渗透率意在代表单位水力梯度下的长期水力传导率。在4000多个土壤类群中，大多数(67%)的渗透性在0.60至2.00英寸/小时范围内，这是一个常见的但范围很广的范围。

渗透率值被用于为气象站分配一个水文组类，用于用USDA-NRCS曲线数法估算降水径流。三个主要水文类群A(粗质土)、B(中质土)和C(细质土)的渗透率范围为:

- Hydrologic Group A - 0 to 1 inch per hour 
- Hydrologic Group B – 1 to 4 inch per hour 
- Hydrologic Group C - > 4 inch per hour

也就是说这块主要两个数据对接下来的计算比较关键，一个是土壤持水量（计算和AWC相关的量），一个是土壤渗透率（选择降雨径流模型）

在日水量平衡模型的应用中，模拟了从土壤表层上层0.10到0.15 m的蒸发过程，其中REW(易蒸发水量)和TEW(总蒸发水量)项需要从 Available Water Holding Capacity（AW）来估计：
$$REW=0.8+54.4\frac{AW}{1000}$$
$$TEW=-3.7+166\frac{AW}{1000}$$

## RUNOFF FROM PRECIPITATION

产流模型是使用USDA-NRCS Curve Number approach计算的。需要的数据是daily precipitation depth 和 日土壤水量平衡计算得到的前期土壤含水条件。

curve number（CN） 代表了土壤-植被复合体的相对不透水性，其范围从0(无限渗透)到100(完全不透水性和全部径流)。一般来说，CN值根据一般作物和土壤类型从标准表中选择，并根据wetting 事件前的土壤含水量进行调整。CN程序中的参数S是在单一降水事件中作为入渗和冠层截留可保留的最大水深[mm]：
$$S=250(\frac{100}{CN}-1)$$
surface runoff is then calculated for P > 0.2 S as：
$$RO=\frac{(P-0.2S)^2}{P+0.8S}$$
如果P<0.2S，就不产流。

曲线数受降雨前土壤含水量的影响，因为土壤含水量影响土壤入渗速率。因此，CN是根据降雨事件前估算的土壤含水量进行调整的。这种土壤含水量称为“土壤水分条件”或AWC。在干燥(AWC I)和潮湿(AWC III)条件下，CN的调整范围由USDA-SCS(1972)定义。USDA-SCS将AWC I定义为“流域土壤足够干燥，可以进行令人满意的耕作”，而AWC III则定义为“流域由于前期降雨实际上已经饱和”。(美国国家工程手册，第4节水文，1972年，第4.10页)。AWC II定义为“平均条件”，值参考原文表6.1.

Hawkins等人(1985)用AWC I和AWC III的CN与AWC II的CN的方程表示了USDA-SCS中的表格关系：
$$CN_I=\frac{CN_{II}}{2.281-0.1281CN_{II}}$$
$$CN_{III}=\frac{CN_{II}}{0.427+0.00573CN_{II}}$$
土壤表层水分平衡与dual Kc程序可以用来估计AWC条件。CN的具体计算可以参考原文6.7-6.9公式。

## EVAPORATION DURING WINTERTIME

nongrowing (wintertime) periods 的蒸发量变化很大，这取决于水分有效性、土壤冻结、积雪、表面有机覆盖物(死亡植被)的影响和蒸发量。

为了估计非生长期的Kc，basal Kcb=0.1 用到 bare soil 条件，mulch 覆盖的surfaces，还有dormant turf/sod system。Kcb表示这些表面有一个干燥的土壤表面，但在深层有足够的水分来提供一些蒸发的条件。蒸发量(Ke)分量在日土壤水分平衡中单独计算，其中裸地期Kc max为0.9，覆膜期Kc max为0.85，休眠期草被期Kc max为0.8。草的低值反映了草的绝缘效应和较高的反照率。第三种表面覆盖类型的覆盖物，被用来表示裸露和草地条件之间的部分表面。在估算Ke时，假设休眠草的有效覆盖度为0.7，覆盖层为0.4，裸地为0。

Kcb的低值允许日常计算中的Ke函数根据雨雪湿润频率增加总Kc的值。

覆盖层下的部分表面采用0.10 m的有效“rooting zone”。对于所有表面，进行每日土壤水分平衡，并在土壤含水量低于临界值(上层0.10 - 0.15 m)时施加Ks。因此，当地表和地下土壤均为干燥时，实际Kc降低到Kcb以下。

不生长季节(冬季)时期被定义为周期结束时开始Kcb曲线代表特定作物的生长周期或发生灾难性霜冻,到最后greenup或者种植同一作物的第二年(或10月1日在冬小麦的情况下)。

所有土地利用类型，包括农业、景观、园艺和自然植被，**都被指定为三种冬季覆盖条件之一(休眠草、裸地或覆盖层类别)**，以估计冬季蒸发损失。

关于snow cover的影响可以详见原文式7.1-7.6

## ESTIMATING BEGINNING AND END OF GROWING SEASONS

春季**多年生植物的绿化(绿化)会受到短期天气条件的强烈影响**，主要是受气温、某种程度上受湿润事件和一般太阳辐射的影响。**气温、湿度和云量之间存在较强的相关性，一般可以作为多年生植物春季开始绿化的预测因子**。同样，**一年生作物的种植日期也受到一般温度条件的影响**。种子深度的土壤温度对种植影响很大，一些作物已经建立了相关关系。然而，土壤温度通常不是在合作的NWS气象站测量的，只有在区域类型的气象站才可以测量。因此，由于土壤温度与空气温度在很长一段时间内具有很强的相关性，因此**将30天平均日空气温度作为土壤温度的替代品**。

**T30的值是从每种作物种植的年份中选取的**。Allen和Brockway(1983)使用长期T30值和种植或greenup为牧场、果园、蔬菜和洋葱作物建立了类似的T30值。**这些日期被用作全州T30日期的一般基础，用于估算生长期的开始**。原文表8.1中大部分作物T30日期的标准差为14天左右。因此，从统计数据上看，68%的起始时间将在平均初创日期的大约14天内开始。(个人理解，T30/CGDD for greenup 是根据调查出来的，而T30反映的是greenup需要的heat unit，因此是可以用到不同年来根据实际的温度情况推出greenup date)

在对农作物和天然植被的种植或greenup日期进行估算时，**采用“no earlier than”和“no later than”的日期**，根据农民或植被本身的预期行为，将估算日期限制在现实范围内。根据长期平均温度，对大多数作物来说，这是平均日期+/- 40天（个人理解，也就是每个grrenup日期都应该在平均日期正负40天内）

ETc processing期间作物T30的最终值列在正文的表7中。表8.3根据金伯利37年的气温记录，总结了爱达荷州中南部常见的7种灌溉作物的种植或greenup日期的估计数据。表的第二行显示了根据用于作物的T30值估计的每种作物类型的平均日期。对于**alfalfa，greenup是基于1月1日以来的CGDD**。alfalfa还有cutting dates，也是根据历史记录用CGDD估计的。dairy and beef alfalfa types 是典型的cutting 方式。（关于cutting后 Kcb的相关处理还是看代码）

前面是growing season的开始的估计，现在看看 Killing Frosts 的估计

对于那些生长到秋天较晚的作物或对轻度霜冻都很敏感的作物来说，杀死霜冻可以提前终止其生长季节。根据文献资料、互联网搜索和个人田间记录，大多数作物的冻害温度被指定。

## 2005 Allen 文献对FAO-56的三个扩展

首先是 Separate Prediction of Evaporation from Soil Wetted by Precipitation Only。

在这个扩展算法里，Ke的计算分成了两个部分，一个时针对既有灌溉也有降水的情况，一个是针对只有降水的情况。
$$K_e=K_{ei}+K_{ep}$$
因此，公式$K_e=K_r(K_{c\ max}-K_{cb})\leq f_{ew}K_{c\ max}$就改为了两个：
$$K_{ei}=K_{ri}W(K_{c\ max}-K_{cb})\leq f_{ewI}K_{c\ max}$$
$$K_{ep}=K_{rp}(1-W)(K_{c\ max}-K_{cb})\leq f_{ewp}K_{c\ max}$$
其中，
$$f_{ewi}=min(1-f_c,f_w)$$
$$f_{ewp}=1-f_c-f_{ewi}$$
后面平衡计算也都变成两种分别算了。这里暂不赘述。

然后是对surface layer 蒸腾的处理，之前是直接忽略了，不过对于shallow-rooted 年生长作物，计算一下还是更好一些。

最后，就是两阶段平衡模型改为了三阶段，把crop在深度缺水条件下干裂引发的更深程度的耗水模拟为第三阶段。因此Kr就多出了各Kr2，然后TEW本来就一个，现在变为一个TEW2和一个TEW3。然后Kr的计算也有变化，第二阶段的公式：
$$K_r=K_{r2}+(1-K_{r2})\frac{TEW_2-D_{e,j-1}}{TEW_2-REW}$$
其中，$REW<D_{e,j-1}<TEW_2$
第三阶段的公式：
$$K_r=K_{r2}\frac{TEW_3-D_{e,j-1}}{TEW_3-TEW_2}$$
其中，$TEW_2\leq D_{e,j-1}$

$K_{r2}$推荐值为0.2.