/**
 * \file cannyParametersControlWidget.cpp
 * \attention This file is automatically generated and should not be in general modified manually
 *
 * \date MMM DD, 20YY
 * \author autoGenerator
 */

#include "cannyParametersControlWidget.h"
#include "ui_cannyParametersControlWidget.h"
#include <memory>
#include "qSettingsGetter.h"
#include "qSettingsSetter.h"


CannyParametersControlWidget::CannyParametersControlWidget(QWidget *parent, bool _autoInit, QString _rootPath)
    : FilterParametersControlWidgetBase(parent)
    , mUi(new Ui::CannyParametersControlWidget)
    , autoInit(_autoInit)
    , rootPath(_rootPath)
{
    mUi->setupUi(this);

    QObject::connect(mUi->shouldEdgeDetectCheckBox, SIGNAL(stateChanged(int)), this, SIGNAL(paramsChanged()));
    QObject::connect(mUi->minimumThresholdSpinBox, SIGNAL(valueChanged(int)), this, SIGNAL(paramsChanged()));
    QObject::connect(mUi->maximumThresholdSpinBox, SIGNAL(valueChanged(int)), this, SIGNAL(paramsChanged()));
}

CannyParametersControlWidget::~CannyParametersControlWidget()
{

    delete mUi;
}

void CannyParametersControlWidget::loadParamWidget(WidgetLoader &loader)
{
    std::unique_ptr<CannyParameters> params(createParameters());
    loader.loadParameters(*params, rootPath);
    setParameters(*params);
}

void CannyParametersControlWidget::saveParamWidget(WidgetSaver  &saver)
{
    saver.saveParameters(*std::unique_ptr<CannyParameters>(createParameters()), rootPath);
}

void CannyParametersControlWidget::getParameters(CannyParameters& params) const
{
    params = *std::unique_ptr<CannyParameters>(createParameters());
}


CannyParameters *CannyParametersControlWidget::createParameters() const
{

    /**
     * We should think of returning parameters by value or saving them in a preallocated place
     **/


    return new CannyParameters(
          mUi->shouldEdgeDetectCheckBox->isChecked()
        , mUi->minimumThresholdSpinBox->value()
        , mUi->maximumThresholdSpinBox->value()
    );
}

void CannyParametersControlWidget::setParameters(const CannyParameters &input)
{
    // Block signals to send them all at once
    bool wasBlocked = blockSignals(true);
    mUi->shouldEdgeDetectCheckBox->setChecked(input.shouldEdgeDetect());
    mUi->minimumThresholdSpinBox->setValue(input.minimumThreshold());
    mUi->maximumThresholdSpinBox->setValue(input.maximumThreshold());
    blockSignals(wasBlocked);
    emit paramsChanged();
}

void CannyParametersControlWidget::setParametersVirtual(void *input)
{
    // Modify widget parameters from outside
    CannyParameters *inputCasted = static_cast<CannyParameters *>(input);
    setParameters(*inputCasted);
}
