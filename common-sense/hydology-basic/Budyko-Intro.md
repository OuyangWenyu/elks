# Budyko简介

Budyko，虽然国内工程水文教材上没有怎么提及它，但是在很多文献中都有涉及，首先这是个人名，然后伴随其的是一系列名词，Budyko hypothesis, Budyko curve, Budyko equation, Budyko model等等。本文就围绕这些名词展开以快速地了解下基本内容。

## Budyko

这部分内容摘自维基百科[Mikhail Budyko](https://en.wikipedia.org/wiki/Mikhail_Budyko)。

Mikhail Ivanovich Budyko是前苏联，俄罗斯的气候学家，是 physical climatology奠基人之一。他开创地利用能量平衡研究全球气候和地球温度计算，其书籍Heat Balance of the Earth's Surface是将气候学从定性分析转向定量计算的标志性著作。

关于Budyko有一些有趣的故事，根据这篇[blog](https://zhuanlan.zhihu.com/p/40391203)，1966年，Budyko借助计算机模型指出，在温度下降十分剧烈的时候，冰或雪的覆盖范围一旦超过纬度30°这个阈值，就会引发不可逆转的降温，并导致地球表面完全冻结。冰层的白色表面能够反射超过60%的阳光，如果地球上接收太阳光最多的地区反射率上升，地球的温度也难以回升，进入了不断降温的恶性循环，它的表面将完全冻结，这让人想起来一个冰封世界的灾难片－－后天。根据另一篇[文章](https://zhuanlan.zhihu.com/p/66697421)，Budyko还率先就工业系统不断燃烧化石燃料将不可避免地加速全球气候变化发出了一系列警告。虽然人类活动会导致气候快速变化早已得到认可，但重要的是布迪科新发现了气候反馈机制，例如北极冰川融化，如果冰川减少，冰川对太阳辐射的反射就会减少，地球吸收的太阳辐射量就会增加，全球平均温度会提高。1974年，布迪科提出，作为气候变化的可能解决方案，使用高空飞机将硫颗粒（形成硫酸盐气溶胶）释放到平流层。这是在模仿火山活动推动硫气进入大气层，从而形成局部屏障，限制进入地球的太阳辐射。布迪科认为，资本主义经济以资本积累为基础，尽管存在对气候的危险，但资本主义经济无法限制对能源的使用和排放。因此，必须探索稳定气候的技术替代方案。

奇闻轶事就到这里，接下来重点了解下水文相关的理论。

## Budyko hypothesis

根据文献[The Budyko hypothesis before Budyko: The hydrological legacy of Evald Oldekop](https://doi.org/10.1016/j.jhydrol.2016.02.002)所述，在水文领域, the Budyko hypothesis 指的是地表长期水和能量平衡很大程度上取决于a single aridity ratio：$\phi = E_x/P$
其中，P表示长期precipitation，单位mm/yr，$E_x$ 表示长期maximum evaporation，单位mm/yr。这里说的长期long-term通常指的是decade，更好的是指three decades。因为这样可以忽略流域storage dynamics (both soil moisture and ground water)以及estimate E based on measured catchment streamflow and precipitation. 这时，$\phi = E_x/P$就变得有用了，表示 the aridity ratio，其倒数$P/E_x$称为the humidity ratio.

根据文献[The use of the aridity index to assess climate change effect on annual runoff](https://doi.org/10.1016/S0022-1694(02)00101-4)所述，Available energy (通常expressed in terms of potential evaporation)和 precipitation很大程度上决定了一个区域的annual evapotranspiration 和 runoff rates. 有一些研究用annual potential evaporation 与 precipitation 的比值，即the aridity index(by Budyko), 来描述流域the evaporation ratio (the ratio of annual evapotranspiration to precipitation)  from **a range of climatic regimes**. 这表明aridity index 能单独用来获取 an estimate of ratio of standard deviation of annual evapotranspiration estimates to that of precipitation (the evaporation deviation ratio)

这里稍作总结，首先补充一下关于蒸发的一些基础知识。这一小部分主要参考了[Methods of estimating potential and actual evaporation](https://www.researchgate.net/file.PostFileLoader.html?id=58b6feb8f7b67e3dc71ca3c1&assetKey=AS%3A467146313605122%401488387768864)（注意点击即下载了）。这篇小文章主要介绍了经典的potential 和 actual evaporation的估算方法，以帮助快速了解蒸发背后的知识。先看定义，The evaporation plus transpiration from a vegetated surface with unlimited water supply is known as potential evaporation or potential evapotranspiration (PE). 这表示了在prevailing meteorological conditions下的最大可能蒸散发率，因此PE就是实际蒸发$E_t$ 的最大值 ： $PE=E_t$ 当water supply is unlimited. 而实际蒸发就是正常一天地表水的蒸发量。对PE就常用的测量方式是irrigated lysimeter，中文叫测渗计，详情可google。很多情况下，PE是计算得来的，比如著名的Penman公式，详情可google。计算实际蒸发有常用的Penman-Monteith公式，测量实际蒸发的仪器有percolation gauge。

根据以上内容，简单归纳，就是说水文上研究一个流域的水和能平衡时，很重要的就是研究降雨和蒸发，而在长期范围内，$E_x/P$ 对蒸发率有指示性的作用。而这种作用的一个代表性理论就是Budyko hypothesis。

根据文献[Improving Budyko curve‐based estimates of long‐term water partitioning using hydrologic signatures from GRACE](https://doi.org/10.1002/2016WR018748)所述，Budyko hypothesis描述了长期范围内降水P在蒸发E和径流Q之间的分配：
$$\frac{E}{P}=f(\frac{E_p}{P})$$
即$E/P$是$E_p/P$的函数,$E_p/P$就是前文提到的potential evaporation与precipitation之间的比值，即 the aridity ratio. 这里面的f就是Budyko曲线了。

## Budyko curve

回到前面所讲的EP与P的比值，EP通常会用demand来指代，意指区域的蒸发需求，表达的是available energy，蒸发是有潜热的，所以是energy；对应的P常用supply指代，意思是大自然能提供的水分。这种供需关系指示了流域水热循环的特点，如果供需比较大，那么对于一定量的降雨，径流更可能超过蒸发，反之则径流少，这对流域中长期的径流预报是有指导意义的。

具体看看EP与P的关系，在供需比很小的地方，蒸发是接近降水的，反之，蒸发是接近潜在蒸发的。这两个值即P和EP值被available water和available energy限制。

回来到Budyko curve，根据前文所述，就是f，那么f曲线是如何定义的呢？如前所述，定义f的一个指标就是the aridity ratio，而这个指标是和 climatic regimes紧密相关的，比如干旱，半干旱，半湿润，湿润。因此，Budyko曲线实际上是一系列climatic regimes代表的曲线簇。至于其具体的数学表达，有很多形式。

根据文献[New analytical derivation of the mean annual water‐energy balance equation](https://doi.org/10.1029/2007WR006135)，流域尺度长期的The coupled water‐energy balance能用 a set of partial differential equations 表示, 且其有通解形式－－ $E/P = F(E_0/P, c)$, where c is a parameter. 参数$(P,E_0,E)$的状态空间是$P - E_0 - E$三维空间中的一组曲面，这组曲面在$E/P - E_0/P$二维空间的投影即是Budyko-type的曲线。这篇文章的详细内容和数学推导等以后有时间再看，因为本文意在科普了解，所以这篇文章的推导暂略了，后面有一些更基础的补充。偏微分方程的解析解形式是$E=E_0P/(P^n+E_0 ^n)^{1/n}$, 参数n代表流域特性。此解析解对气候和土地利用变化对水文圈的影响的评价是很有用的理论工具，所以有很多用Budyko方程来研究气候变化的影响的。接下来再进一步看看Budyko Equation的具体内容。

## Budyko Equation

这部分参考[Understanding the Budyko Equation](https://www.mdpi.com/2073-4441/9/4/236/pdf)(注意此链接也是直接下载的)等文献。如前文所述的由于现在人类活动和气候变化的影响，人们对Budyko方程的预测应用重燃兴趣。这些应用反过来激发了很多对Budyko Equation数学模型的推导。这里就记录下部分关于Budyko Equation的基本推导。

Green Water是包气带中能被植物或微生物吸收的水。green water的流动主要依靠蒸发，通过地表蒸发或植物蒸腾进入大气。在全球蒸发、径流角度看，蒸发是十分重要的，全球地表蒸发大约多于年径流量54%. 然而不论时间还是空间，地表蒸发terrestrial evapotranspiration (ET),都是一个很难直接量化的量，即使是在一个站点，因此联合基于地面的，卫星的和模型的间接观测成为了常用的确定流域级到全球级蒸发量的方法。

T(transpiration)，ET(evapotranspiration)的组成部分，也称为"productive green water flow"，因为这部分是支撑碳同化和植物生长的，不过由于ET难测量，T的相关问题依然存在挑战。有人研究的全球的平均T和runoff相当；在流域尺度，ET是水文过程的关键，既是生态系统的关键指标，也是人类不可用的水，这对水资源管理很重要，尤其在人类活动及气候变化的影响下。

蒸发伴随着吸热过程，因此ET不仅反映水的分配，也反映大气与地表的能量交换。Budyko研究方法是不基于本构方程（constitutive equation）的简化解释，而是倾向于仅仅基于任何物理系统都必须遵循的质量能量平衡定律来建立普遍关系。搜索了"constitutive equation"的意思，根据各类[科普信息](https://www.zhihu.com/question/24800744)所述，通俗来讲，宏观上本构模型讲的就是物体的力与变形之间的关系。因为描述一个力学问题一般考虑三大场方程，即质量守恒，动量和动量矩守恒，能量守恒，有时还会需要考虑热力学第二定律。这些方程与材料或者说物体本身无关。因此还需要考虑材料本身的特性，描述材料本身特性的就是本构模型。力学里面考虑材料的力学特性，弹塑性材料是应力应变曲线，考虑粘性或是流体还要考虑应变率甚至应力率，考虑热还要考虑热膨胀系数，声学里是压强与密度的关系。还涉及材料是各向同性还是各向异性。在本文所讨论的蒸发所涉及的水热交换问题中，本构方程的相关知识可参考文献[Heat and water transport in soils and across the soil‐atmosphere interface](https://doi.org/10.1002/2016WR019982)。连续尺度上的蒸发过程的描述模型从复杂的完全耦合的自由流和多孔介质流表示到简化的Richards方程各不相同，不过都是从多孔介质(土壤)，自由流动(即大气）以及多孔介质与自由流动的耦合的流动和输运方面建模。不同科研圈（土壤物理学，水文学，大气科学等）讨论的重点会有所不同，这里面的过程是简化处理还是复杂分析会不一样。这篇文章首先给出了一个porous medium和free flow以及它们之间耦合的 constitutive equations 的概述。这就是蒸发中所提及的 constitutive equation：
![image.png](wrcr22442-fig-0001-m.png)
因为Budyko不是从这个角度出发考虑的，因此这里就不赘述了，回到Budyko equation，它是建立在最基本的质量能量守恒定律上的。其基本思路是**通过包气带的上边界进入大气层的长期平均年green water流量 is subject to相同的应用于全球green water流量的水和能量平衡假设，即地下蓄水层的变化可以忽略不计，地表与包气带之间的净传热可以忽略不计**。在此两者假设基础上，流域尺度的长期平均年水和能平衡可以用下两式表示：
$$P=ET+Q$$
$$R_n=L*ET+H$$
其中P(L/T)是precipitation，ET(L/T)是evapotranspiration，Q(L/T)是runoff，$R_n(M/T^3)$是average annual net radiative heat flux from the atmosphere to the land surface, L$(M/L·T^2)$是 the latent heat of evaporation，乘积$L·ET(M/T^3)$ 是the latent heat flux， $H(M/T^3)$ 是average annual heat flow from the land surface into the atmosphere, the sensible heat flux. 

简言之，第一个是水量平衡，第二是入射能等于潜热加显热的能量平衡。第二个式子可以写为：$$\frac{R_n}{L}=ET+\frac{H}{L}$$ 
根据此式可知，当所有输入的辐射能量都被陆地表面的green water蒸发所消耗时，可作为ET传递的green wter就没有限制，这时感热通量可以忽略不计，此时ET可能达到最大。最大就是$\frac{R_n}{L}$，称为 potential evapotranspiration，由符号$ET_0$表示。

Budyko hypothesis就是说刚所述的方程1和3指出了ET和两个气候变量P和$ET_0$之间存在一个函数关系，这个关系适用于长期时间尺度平均的各个流域：
$$ET=f(P,ET_0)$$
Budyko进一步阐述了该函数关系的限制条件：
$$ET \to ET_0 \  as \ P \uparrow \infty$$
$$ET \to P \  as \ ET_0 \uparrow \infty$$
这两式分别描述了“wet condition”和“dry condition”，如前面所提的供需关系，供水充足情况下，ET就受限于$ET_0$，供水不足的情况下，ET就受限于P。

上面这后三个式子就是Budyko hypothesis的实质内容了。基于Budyko hypothesis，Budyko进一步地给出了$ET=f(P,ET_0)$的具体数学表达，这就是这一小节的核心概念－－Budyko Equation了。接下来就根据实际需要一点点地记录下Budyko Equation的推导过程。

先给定一个前提，$f(ET_0, P)$ is a homogeneous function（中文是齐次） of its arguments，$f(\lambda ET_0, \lambda P) = \lambda ET$, 令$\lambda = 1/P$，所以有$\frac{ET}{P} = f(\frac{ET_0}{P})$。

稍微补充下[齐次函数](https://en.wikipedia.org/wiki/Homogeneous_function)概念：if all its arguments are multiplied by a factor, then its value is multiplied by some power of this factor。 也就是有形如$f(ax,ay)=a^2 f(x,y)$的特征，a的平方表示是二阶齐次，如果次方为1，那么就是一阶齐次函数。

令$\frac{ET_0}{P}= \phi$,$\phi < 1$ 表示 a humid climate,$\phi> 1$  表示 an arid climate。则有：
$$ET/P \downarrow \phi \ as \ \phi \downarrow 0$$
$$ET/P \uparrow 1 \ as \ \phi \uparrow \infty$$
所以就会有下图(b)所示的图形：
![limit](1-s2.0-S0022169416300270-gr1.jpg)

伴随齐次性的有两个重要的属性：

其一，根据文献[Thermodynamics and an Introduction to Thermostatistics](https://www.academia.edu/35013052/Herbert_B._Callen_Thermodynamics_and_an_Introduction_to_Thermostatistics)59－60页的推导，有：$ET=\frac{\partial ET}{\partial P}P+\frac{\partial ET}{\partial ET_0}ET_0$. 根据文献[New analytical derivation of the mean annual water‐energy balance equation](https://doi.org/10.1029/2007WR006135)第二页，Budyko hypothesis下的一阶边界条件有该文式7所示形式。也就是所有偏微分都在[0,1]区间内。

其二，Gibbs－Duhem relation，根据Thermodynamics and an Introduction to Thermostatistics一文60－62页推导有：$P\ d(\frac{\partial ET}{\partial P})+ET_0\ d(\frac{\partial ET}{\partial ET_0})=0$

总之，第一条表明了两个偏导数的$\phi$-dependence的知识足以确定Budyko方程的函数$F(\phi)$；第二条进一步说明了这两个对$\phi$有响应的的偏导数的变化不是独立的，这两条是后面给出$F(\phi)$的重要依据。

$ET/P = F(\phi)$有根据边界条件确定的非参数插值的形式，也有许多参数形式的。其中最主要的两个是the Fu model and the Mezentsev－Choudhury－Yang (MCY) model。以下内容时间有限，并且需要更早期的一些文献补充知识，因此暂时略过，后续再补充。

Budyko model

如前所述，Budyko的方法是“Darwinian”，不是“Newtonian”。这些概念可参考[A one‐parameter Budyko model for water balance captures emergent behavior in darwinian hydrologic models](https://doi.org/10.1002/2014GL060509)，