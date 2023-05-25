# BufferTankModelling

We keep the different elements of the project in the folders *data*, *models*, *libraries* and *uppaal*.<br />
The *data* folder contains the historical data for weather and electricity prices.<br />
The *libraries* folder contains C Libraries we created to perform the following actions<br />
* facilitate the communication between the house model and the controller
* read historical data into the models
* read strategy decisions
* store data from the experiments into external files<br />

The *uppaal* folder contains the uppaal stratego tool package.<br />
The *models* folder contains the uppaal models of the buffer tank and mixing loop that we use for evaluation (EM.xml) and learning (LM.xml).<br />

To open learning model, write the following command from the home directory of the project:

```bash
./run_LM_gui.sh
```
To open evaluation model, write the following command from the home directory of the project:

```bash
./run_EM_gui.sh
```
